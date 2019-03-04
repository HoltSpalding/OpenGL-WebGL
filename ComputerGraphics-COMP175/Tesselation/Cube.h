#ifndef CUBE_H
#define CUBE_H

#include "Shape.h"
#include <iostream>

class Cube : public Shape {
public:
	Cube() {};
	~Cube() {};
	//m_segmentsX, m_segmentsY
	void draw() {
		for (int i = 0; i < m_segmentsY; i++) {
			//1 face
			glBegin(GL_TRIANGLE_STRIP);
			for (int j = 0; j <= m_segmentsX; j++) {
				glVertex3f(-0.5 + (float)j / m_segmentsX, 0.5 - (float)i / m_segmentsY, 0.5);
				glVertex3f(-0.5 + (float)j / m_segmentsX, 0.5 - (float)(i + 1) / m_segmentsY, 0.5);
				//Point
			}
			glEnd();
			//2nd face
			glBegin(GL_TRIANGLE_STRIP);
			for (int j = 0; j <= m_segmentsX; j++) {
				glVertex3f(-0.5 + (float)j / m_segmentsX, 0.5 - (float)i / m_segmentsY, -0.5);
				glVertex3f(-0.5 + (float)j / m_segmentsX, 0.5 - (float)(i + 1) / m_segmentsY, -0.5);
			}
			glEnd();
			//3rd face
			glBegin(GL_TRIANGLE_STRIP);
			for (int j = 0; j <= m_segmentsX; j++) {
				glVertex3f(-0.5, 0.5 - (float)i / m_segmentsY, -0.5 + (float)j / m_segmentsX);
				glVertex3f(-0.5, 0.5 - (float)(i + 1) / m_segmentsY, -0.5 + (float)j / m_segmentsX);
			}
			glEnd();
			//4th face
			glBegin(GL_TRIANGLE_STRIP);
			for (int j = 0; j <= m_segmentsX; j++) {
				glVertex3f(0.5, 0.5 - (float)i / m_segmentsY, -0.5 + (float)j / m_segmentsX);
				glVertex3f(0.5, 0.5 - (float)(i + 1) / m_segmentsY, -0.5 + (float)j / m_segmentsX);
			}
			glEnd();
			//5th face
			glBegin(GL_TRIANGLE_STRIP);
			for (int j = 0; j <= m_segmentsX; j++) {
				glVertex3f(-0.5 + (float)j / m_segmentsX, 0.5 , 0.5 - (float)(i) / m_segmentsY);
				glVertex3f(-0.5 + (float)j / m_segmentsX, 0.5 , 0.5 - (float)(i + 1) / m_segmentsY);
			}
			glEnd();
			//6th face
			glBegin(GL_TRIANGLE_STRIP);
			for (int j = 0; j <= m_segmentsX; j++) {
				glVertex3f(-0.5 + (float)j / m_segmentsX, -0.5, 0.5 - (float)(i) / m_segmentsY);
				glVertex3f(-0.5 + (float)j / m_segmentsX, -0.5, 0.5 - (float)(i + 1) / m_segmentsY);
			}
			glEnd();
		}
	};


	void drawNormal() {
		glColor3f(1.0, 0.0, 0.0);
			for (double i = 0; i <= m_segmentsY; i++) {
				for (double j = 0; j <= m_segmentsX; j++) {
					glBegin(GL_LINES);
						glVertex3f(-0.5 + (float)j / m_segmentsX, 0.5 - (float)i / m_segmentsY, 0.5);
						glVertex3f(-0.5 + (float)j / m_segmentsX, 0.5 - (float)(i) / m_segmentsY, 0.6);
					glEnd();

					glBegin(GL_LINES);
						glVertex3f(-0.5 + (float)j / m_segmentsX, 0.5 - (float)i / m_segmentsY, -0.5);
						glVertex3f(-0.5 + (float)j / m_segmentsX, 0.5 - (float)(i) / m_segmentsY, -0.6);
					glEnd();

					glBegin(GL_LINES);
						glVertex3f(0.5, -0.5 + (float)j / m_segmentsX, 0.5 - (float)i / m_segmentsY);
						glVertex3f(0.6, -0.5 + (float)j / m_segmentsX, 0.5 - (float)(i) / m_segmentsY);
					glEnd();

					glBegin(GL_LINES);
						glVertex3f(-0.5, -0.5 + (float)j / m_segmentsX, 0.5 - (float)i / m_segmentsY);
						glVertex3f(-0.6, -0.5 + (float)j / m_segmentsX, 0.5 - (float)(i) / m_segmentsY);
					glEnd();

					glBegin(GL_LINES);
						glVertex3f(-0.5 + (float)j / m_segmentsX, 0.5, 0.5 - (float)i / m_segmentsY);
						glVertex3f(-0.5 + (float)j / m_segmentsX, 0.6, 0.5 - (float)(i) / m_segmentsY);
					glEnd();

					glBegin(GL_LINES);
						glVertex3f(-0.5 + (float)j / m_segmentsX, -0.5, 0.5 - (float)i / m_segmentsY);
						glVertex3f(-0.5 + (float)j / m_segmentsX, -0.6, 0.5 - (float)(i) / m_segmentsY);
					glEnd();
/*
					glBegin(GL_LINES);
					glVertex3f(0.5,i,j);
					glVertex3f(0.6,i,j);
					glEnd();

					glBegin(GL_LINES);
					glVertex3f(-0.5,i,j);
					glVertex3f(-0.6,i,j);
					glEnd();

					glBegin(GL_LINES);
					glVertex3f(i,0.5,j);
					glVertex3f(i,0.6,j);
					glEnd();

					glBegin(GL_LINES);
					glVertex3f(i,-0.5,j);
					glVertex3f(i,-0.6,j);
					glEnd();
*/
				}
			}
	};

	void initPoint() {
		/*
		for (int i = 0; i < m_segmentsY; i++) {
			//1 face
			for (int j = 0; j <= m_segmentsX; j++) {
				Point(-0.5 + (float)j / m_segmentsX, 0.5 - (float)i / m_segmentsY, 0.5);
				Point(-0.5 + (float)j / m_segmentsX, 0.5 - (float)(i + 1) / m_segmentsY, 0.5);
			}
			//2nd face
			for (int j = 0; j <= m_segmentsX; j++) {
				Point(-0.5 + (float)j / m_segmentsX, 0.5 - (float)i / m_segmentsY, -0.5);
				Point(-0.5 + (float)j / m_segmentsX, 0.5 - (float)(i + 1) / m_segmentsY, -0.5);
			}
			//3rd face
			
			for (int j = 0; j <= m_segmentsX; j++) {
				glVertex3f(-0.5, 0.5 - (float)i / m_segmentsY, -0.5 + (float)j / m_segmentsX);
			}
			//4th face
			for (int j = 0; j <= m_segmentsX; j++) {
				glVertex3f(0.5, 0.5 - (float)i / m_segmentsY, -0.5 + (float)j / m_segmentsX);
			}
			//5th face
			for (int j = 0; j <= m_segmentsX; j++) {
				glVertex3f(-0.5 + (float)j / m_segmentsX, 0.5 , 0.5 - (float)(i) / m_segmentsY);
			}
			//6th face
			for (int j = 0; j <= m_segmentsX; j++) {
				glVertex3f(-0.5 + (float)j / m_segmentsX, -0.5, 0.5 - (float)(i) / m_segmentsY);
			}
		}
		*/
	};
};

#endif