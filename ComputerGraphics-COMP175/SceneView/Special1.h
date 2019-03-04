#ifndef SPECIAL2_H
#define SPECIAL2_H

#include "Shape.h"

class Special2 : public Shape {
public:
	Special2() {};
	~Special2() {};

	void draw() {
	
 


	double R = 0.375;
	//double r = 0.125;
	double x, y, z, phi;
	double r;
	for (int i = 0; i < m_segmentsY; i++) {
	r = -0.125 + i * 0.250/(float)m_segmentsY;
	glBegin(GL_TRIANGLE_STRIP);
		for (int j = 0; j <= m_segmentsX; j++) {
			phi = j * 2 * PI / (float)m_segmentsX;
			x = (R + r * cos(phi/2)) * cos(phi);
			y = r * sin(phi/2);
			z = (R + r * cos(phi/2)) * sin(phi);
			glVertex3f(x,y,z);

			x = (R + ((r+0.250/(float)m_segmentsY) * cos(phi/2))) * cos(phi);
			y = (r+0.250/(float)m_segmentsY) * sin(phi/2);
			z = (R + ((r+0.250/(float)m_segmentsY) * cos(phi/2))) * sin(phi);
			glVertex3f(x,y,z);
		 
		}
		glEnd();
	}

	};

	void drawNormal() {
		double R = 0.375;
	//double r = 0.125;
		double x, y, z, phi;
		double r;
		double normlen = 0.1;
		Vector vector_circ[60];
		for (int i = 0; i < m_segmentsX; i++) {
			phi = i * 2 * PI / (float)m_segmentsX;
			vector_circ[i][0] = normlen * cos(phi / 2 - PI / 2) * cos(phi);
			vector_circ[i][1] = normlen * sin(phi / 2 - PI / 2) - 0;
			vector_circ[i][2] = normlen * cos(phi / 2 - PI / 2) * sin(phi);
		}
		for (int i = 0; i <= m_segmentsY; i++) {
		r = -0.125 + i * 0.250/(float)m_segmentsY;
			for (int j = 0; j < m_segmentsX; j++) {
				glBegin(GL_LINES);
				phi = j * 2 * PI / (float)m_segmentsX;
				x = (R + r * cos(phi/2)) * cos(phi);
				y = r * sin(phi/2);
				z = (R + r * cos(phi/2)) * sin(phi);
				glVertex3f(x - vector_circ[j][0], y - vector_circ[j][1], z - vector_circ[j][2]);
				glVertex3f(x + vector_circ[j][0], y + vector_circ[j][1], z + vector_circ[j][2]);
				glEnd();
			}
		}
	};
};

#endif