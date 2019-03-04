#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"

class Sphere : public Shape {
public:
	Sphere() {};
	~Sphere() {};

	void draw() {
		glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0, 0.5, 0);
		double i, j;
		double phi = PI / m_segmentsY;
		for (double i = 0; i < 2 * PI; i += 2 * PI / m_segmentsX) {
			glVertex3f(0.5 * cos(i) * sin(phi), 0.5 * cos(phi), 0.5 * sin(i) * sin(phi));
		}
		glVertex3f(0.5 * cos(0) * sin(phi), 0.5 * cos(phi), 0.5 * sin(0) * sin(phi));
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0, -0.5, 0);
		//double phi = 0.75 * PI;
		for (double i = 0; i < 2 * PI; i += 2 * PI / m_segmentsX) {
			glVertex3f(0.5 * cos(i) * sin(phi), -0.5 * cos(phi), 0.5 * sin(i) * sin(phi));
		}
		glVertex3f(0.5 * cos(0) * sin(phi), -0.5 * cos(phi), 0.5 * sin(0) * sin(phi));
		glEnd();

		for (j = 1; j < m_segmentsY-1; j ++ ) {
			glBegin(GL_TRIANGLE_STRIP);
			for (i = 0; i < 2 * PI; i += 2 * PI / m_segmentsX) {
				glVertex3f(0.5 * cos(i) * sin(j*phi), 0.5 * cos(j*phi), 0.5 * sin(i) * sin(j*phi));
				glVertex3f(0.5 * cos(i) * sin((j+1)*phi), 0.5 * cos((j+1)*phi), 0.5 * sin(i) * sin((j+1)*phi));
			}
			glVertex3f(0.5 * sin(j*phi), 0.5 * cos(j*phi), 0);
			glVertex3f(0.5 * sin((j + 1)*phi), 0.5 * cos((j + 1)*phi), 0);
			glEnd();
		}
	};

	void drawNormal() {

		glBegin(GL_LINES);
		double x1, y1, z1, x2, y2, z2, theta, phi;
		double r1 = .5;
		double r2 = .55;

		for (int i = 0; i < m_segmentsY; i++) {
			for (int j = 0; j < m_segmentsX; j++) {
				theta = 2.0 * PI * (float)j / (float)m_segmentsX;
				phi = PI * (float) i / (float)m_segmentsY;
				x1 = r1 * cos(theta) * sin(phi);
				y1 = r1 * sin(theta) * sin(phi);
				z1 = r1 * cos(phi);
				x2 = r2 * cos(theta) * sin(phi);
				y2 = r2 * sin(theta) * sin(phi);
				z2 = r2 * cos(phi);				
				glVertex3f(x1, z1, y1);
				glVertex3f(x2, z2, y2);
			}
		}
		glEnd();
	};
};

#endif