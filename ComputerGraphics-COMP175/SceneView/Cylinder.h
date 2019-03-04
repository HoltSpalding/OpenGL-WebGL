#ifndef CYLINDER_H
#define CYLINDER_H

#include "Shape.h"
#include "stdlib.h"
#include "stdio.h"
#include <iostream> 

class Cylinder : public Shape {
public:
	Cylinder() {};
	~Cylinder() {};

	void draw() {
		//top cap
		double slicearray[60];
		double interval = 2 * PI / m_segmentsX;
		double height = 1;
		double vinterval = height / m_segmentsY;
		double radius = 0.5;
		int i, j;
		for (i = 0; i < m_segmentsX; i++) {
			slicearray[i] = interval * i;
		}
		slicearray[m_segmentsX] = 2 * PI;
			glBegin(GL_TRIANGLE_FAN);
			glNormal3f(0, 1, 0);
			glVertex3f(0, height/2, 0);
			for (j = 0; j <= m_segmentsX; j ++) {
				glVertex3f(radius*cos(slicearray[j]),height/2, radius*sin(slicearray[j]));
			}
			glVertex3f(radius, height/2, 0);
			glEnd();
			glBegin(GL_TRIANGLE_FAN);
			glNormal3f(0, -1, 0);
			glVertex3f(0, -height/2, 0);
			for (j = 0; j <= m_segmentsX; j++) {
				glVertex3f(radius*cos(slicearray[j]), -height/2, radius*sin(slicearray[j]));
			}
			glVertex3f(radius, -height/2, 0);
			glEnd();

			//Barrel

			for (i = 0; i < m_segmentsY; i++) {
				glBegin(GL_TRIANGLE_STRIP);
				for (j = 0; j < m_segmentsX; j++) {
					glNormal3f(radius*cos(slicearray[j]), 0, radius*sin(slicearray[j]));
					glVertex3f(radius*cos(slicearray[j]), height / 2 - i * vinterval, radius*sin(slicearray[j]));
					glVertex3f(radius*cos(slicearray[j]), height / 2 - (i+1) * vinterval, radius*sin(slicearray[j]));
				}
				glVertex3f(radius, height / 2 - i * vinterval, 0);
				glEnd();
			}
		
	};

	void drawNormal() {
		double slicearray[60];
		double interval = 2 * PI / m_segmentsX;
		double height = 1;
		double vinterval = height / m_segmentsY;
		double radius = 0.5;
		int i, j;
		for (i = 0; i < m_segmentsX; i++) {
			slicearray[i] = interval * i;
		}
			for (i = 0; i <= m_segmentsY; i++) {
				glBegin(GL_LINES);
				for (j = 0; j < m_segmentsX; j++) {
					glVertex3f(radius*cos(slicearray[j]), height / 2 - i * vinterval, radius*sin(slicearray[j]));
					glVertex3f((radius + 0.05)*cos(slicearray[j]), height / 2 - (i) * vinterval, (0.05 + radius)*sin(slicearray[j]));
				}
				glEnd();
			}
	};
};
#endif