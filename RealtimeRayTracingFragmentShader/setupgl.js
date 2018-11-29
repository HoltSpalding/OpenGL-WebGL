function getvertexandfragshadercontext(id) {
    var node = document.getElementById(id);
    console.log(node);
    var gothruDOM = function gothruDOM(child, context) {
        if (child) {
            if (child.nodeType === Node.TEXT_NODE) {
                context += child.textContent;
            }
            return gothruDOM(child.nextSibling, context);
        } else {
            return context;
        }
    };
    return gothruDOM(node.firstChild, '');
}


function gl_init(gl, vertexShader, fragmentShader) {
    var program = gl.createProgram();
    var buffer = gl.createBuffer();


    //Add shaders
    //add vertex shader
    var vshader = gl.createShader(gl.VERTEX_SHADER);
    gl.shaderSource(vshader, vertexShader);
    gl.compileShader(vshader);
    if (!gl.getShaderParameter(vshader, gl.COMPILE_STATUS)) {
        throw "V shader messed up " + gl.getShaderInfoLog(shader);
    }
    gl.attachShader(program, vshader);


    //add fragment shader
    var fshader = gl.createShader(gl.FRAGMENT_SHADER);
    gl.shaderSource(fshader, fragmentShader);
    gl.compileShader(fshader);
    if (!gl.getShaderParameter(fshader, gl.COMPILE_STATUS)) {
        throw "F shader messed up " + gl.getShaderInfoLog(shader);
    }
    gl.attachShader(program, fshader);

    gl.linkProgram(program);

    if (! gl.getProgramParameter(program, gl.LINK_STATUS))
        throw "Could not link the shader program!";
    gl.useProgram(program);

    // Create canvas
    gl.bindBuffer(gl.ARRAY_BUFFER, buffer);
    gl.bufferData(
        gl.ARRAY_BUFFER,
        new Float32Array([
            -1,1,
            0,1,
            1,0,
            -1,-1,
            0,1,
            -1,0]),
        gl.STATIC_DRAW
    );

    gl.time = gl.getUniformLocation(program, "time");
    gl.ballHeight = gl.getUniformLocation(program, "ballHeight");

    gl.aPosition = gl.getAttribLocation(program, "aPosition");
    gl.enableVertexAttribArray(gl.aPosition);
    gl.vertexAttribPointer(gl.aPosition, 3, gl.FLOAT, false, 0, 0);
}

// when animation starts
var inittime = (new Date()).getTime() / 1000;
var falling = true;
var H1 = -1.0;
var t = 0;
var vel = 0;
var g = 0.1;

function retballh() {
     if (falling == true) {
                 H1 = H1 + (vel*t) + (g * t * t);
            }
             if (falling == false) {
                vel = vel + (g * t * t)*0.1;
                H1 = H1 + (vel*t) + (g * t * t);
            }
            if (H1 > 1.0) {
                vel = -(g * t * t);
                H1 = 1.0;
                t = 1/60;
                falling = false;

            }
            var change = (vel*t) + (g * t * t);
            if (falling == false && change >= 0 && change <= 0.000001) {
                falling = true;
                vel = 0;
                t = 1/60;
            }
	if (vel >= -0.00068 && vel < 0 && vel != 0) {
            	H1 = -1.0;
            	falling = true;
            	t = 0;
            	vel = 0;
            }
         
          t += (1/60);
          return H1;
}




function gl_update(gl) {
    gl.uniform1f(gl.time, (new Date()).getTime() / 1000 - inittime);
    gl.uniform1f(gl.ballHeight, retballh());
    gl.drawArrays(gl.TRIANGLE_STRIP, 0, 4);
    requestAnimFrame(function() { gl_update(gl); });
}




function start_gl(canvas_id, vertexShader, fragmentShader) {
    try {
        var canvas = document.getElementById(canvas_id);
        var gl = canvas.getContext("experimental-webgl");
    } catch (e) {
        throw "Sorry, your browser does not support WebGL.";
    }

    // Catch mouse events that go to the canvas.

    // Initialize gl. Then start the frame loop.
    gl_init(gl, vertexShader, fragmentShader);
    gl_update(gl);
}

// A browser-independent way to call a function after 1/60 second.
requestAnimFrame = (function() {
    return requestAnimationFrame
        || webkitRequestAnimationFrame
        || mozRequestAnimationFrame
        || oRequestAnimationFrame
        || msRequestAnimationFrame
        || function(callback) {
               setTimeout(callback, 1000 / 60);
           }; })();

