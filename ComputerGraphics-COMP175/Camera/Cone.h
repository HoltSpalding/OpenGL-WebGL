#ifndef COHE_H
#define CONE_H

#include "Shape.h"

class Cone : public Shape {
public:
	Cone() {};
	~Cone() {};

	void draw() {
		double height = 1.0;
		double vint = height / m_segmentsY;
		double hint = 2 * PI / m_segmentsX;
		int i, j;

		double radius_prop[61];
		for (j = 0; j <= m_segmentsY; j++) {
			radius_prop[j] = j * vint;
		}
		//Base

		glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0, -0.5, 0);
		for (j = 0; j < m_segmentsX; j++) {
			glVertex3f(0.5*cos(hint*j), -0.5, 0.5*sin(hint*j));
		}
		glVertex3f(0.5, -0.5, 0);
		glEnd();

		//Top
		glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0, 0.5, 0);
		double temp = radius_prop[1];
		for (j = 0; j < m_segmentsX; j++) {
			glVertex3f(0.5*cos(hint*j)*temp, 0.5 - temp, 0.5*sin(hint*j)*temp);
		}
		glVertex3f(0.5*temp, 0.5 - temp, 0);
		glEnd();

		//Cone

		for (j = 1; j < m_segmentsY; j++) {
			glBegin(GL_TRIANGLE_STRIP);
			for (i = 0; i < m_segmentsX; i++) {
				glVertex3f(0.5*cos(hint*i) * radius_prop[j], 0.5 - radius_prop[j], 0.5*sin(hint*i)*radius_prop[j]);
				glVertex3f(0.5*cos(hint*i) * radius_prop[j + 1], 0.5 - radius_prop[j + 1], 0.5*sin(hint*i)*radius_prop[j + 1]);
			}
			glVertex3f(0.5* radius_prop[j], 0.5 - radius_prop[j], 0);
			glVertex3f(0.5*radius_prop[j + 1], 0.5 - radius_prop[j + 1], 0);
			glEnd();
		}
	};

	void drawNormal() {

		int i, j;
			double height = 1.0;
			double vint = height / m_segmentsY;
			double hint = 2 * PI / m_segmentsX;
			double radius_prop[61];

			Vector vector_circ[60];

			for (j = 0; j <= m_segmentsY; j++) {
				radius_prop[j] = j * vint;
			}
			double opp = sin(atan(2));
			double adj = cos(atan(2));
			float normLen = 0.1;

			float normhori = normLen * opp;
			float normvert = normLen * adj;

			for (i = 0; i < m_segmentsX; i++) {
				vector_circ[i][0] = normhori * cos(hint*i);
				vector_circ[i][1] = normvert;
				vector_circ[i][2] = normhori * sin(hint*i);
			}

			/* Remake array*/
			Point target;
			for (j = 1; j <= m_segmentsY; j++) {
				for (i = 0; i < m_segmentsX; i++) {
					target[0] = 0.5*cos(hint*i) * radius_prop[j];
					target[1] = 0.5 - radius_prop[j];
					target[2] = 0.5*sin(hint*i)*radius_prop[j];
					glBegin(GL_LINES);
					glVertex3f(target[0], target[1], target[2]);
					glVertex3f(target[0] + vector_circ[i][0], target[1] + vector_circ[i][1], target[2] + vector_circ[i][2]);
					glEnd();
				}
			}
	};

	void initPoint() {
	};
};

#endif