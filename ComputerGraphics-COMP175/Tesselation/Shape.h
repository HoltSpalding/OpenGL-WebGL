#ifndef SHAPE_H
#define SHAPE_H

#include <GL/glui.h>
#include "Algebra.h"

class Shape {
public:
	Shape() {};
	~Shape() {};

	void setSegments(int x, int y) {
		if ((m_segmentsX!=x) || (m_segmentsY!=y)){
		m_segmentsX = x;
		m_segmentsY = y;
		change = true;
	}
	}

	virtual void draw() {};
	virtual void drawNormal() {};
	virtual void initPoint() {}; 

protected:
	void normalizeNormal (float x, float y, float z) {
		normalizeNormal (Vector(x, y, z));
	};

	void normalizeNormal (Vector v) {
		v.normalize();
		glNormal3dv(v.unpack());
	};

	int m_segmentsX, m_segmentsY;
	Point* endpoint;
	Point* points;
	bool change = true;
};

#endif