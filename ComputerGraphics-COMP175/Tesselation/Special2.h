#ifndef SPECIAL2_H
#define SPECIAL2_H

#include "Shape.h"

class Special2 : public Shape {
public:
	Special2() {};
	~Special2() {};

	void draw() {
	double R = 0.350;
	double x, y, z, phi, theta;
	double r = 0.150;
	for (int i = 0; i < m_segmentsY; i++) {
		theta = i * 2 * PI / (float)m_segmentsY;
	glBegin(GL_TRIANGLE_STRIP);
		for (int j = 0; j <= m_segmentsX; j++) {
			phi = j * 2 * PI / (float)m_segmentsX;
			x = (R + r * cos(theta)) * cos(phi);
			y = r * sin(theta);
			z = (R + r * cos(theta)) * sin(phi);
			glVertex3f(x,y,z);

			x = (R + r * cos(theta + 2 * PI / (float)m_segmentsY)) * cos(phi);
			y = r * sin(theta + 2 * PI / (float)m_segmentsY);
			z = (R + r * cos(theta + 2 * PI / (float)m_segmentsY)) * sin(phi);
			glVertex3f(x, y, z);
		 
		}
		glEnd();
	}

	};

	void drawNormal() {
		double R = 0.350;
	//double r = 0.125;
		double x, y, z, phi, theta;	
		double r = 0.150;
		double normlen = 0.1;
		for (int i = 0; i <= m_segmentsY; i++) {
			theta = i * 2 * PI / (float)m_segmentsY;

			for (int j = 0; j <= m_segmentsX; j++) {
				glBegin(GL_LINES);
				phi = j * 2 * PI / (float)m_segmentsX;
				x = (R + r * cos(theta)) * cos(phi);
				y = r * sin(theta);
				z = (R + r * cos(theta)) * sin(phi);
				glVertex3f(x, y, z);

				x = (R + (r + normlen) * cos(theta)) * cos(phi);
				y = (r + normlen) * sin(theta);
				z = (R + (r + normlen) * cos(theta)) * sin(phi);
				glVertex3f(x, y, z);
				glEnd();
			}
		}
	};
};

#endif