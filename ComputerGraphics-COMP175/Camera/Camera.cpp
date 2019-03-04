#include "Camera.h"
#include <GL/glui.h>

Camera::Camera() {
}

Camera::~Camera() {
}

void Camera::Orient(Point& eye, Point& focus, Vector& up) {
	eyePt = eye;
	lookVec = focus - eye; //vector from eyepoint to focus point
	upVec = up;
}


void Camera::Orient(Point& eye, Vector& look, Vector& up) {
	eyePt = eye;
	lookVec = look;
	upVec = up;
}

Matrix Camera::GetProjectionMatrix() {
	double c = -near/far;
	double theta_h = DEG_TO_RAD(viewAng);
	double theta_w = 2*atan(tan(theta_h/2) * GetScreenWidthRatio());
	Matrix unhingingMat = Matrix(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, -1.0/(c+1.0), c/(c+1.0), 0, 0, -1, 0);
	Matrix scalingMat = Matrix((1.0 / (tan(theta_w/2.0) * far)), 0, 0, 0, 0, (1.0 / (tan(theta_h/2.0) * far)), 0, 0, 0, 0, 1.0/(far), 0, 0, 0, 0, 1);
	
	return unhingingMat * scalingMat;
}


void Camera::SetViewAngle (double viewAngle) {
	viewAng = viewAngle;
}

void Camera::SetNearPlane (double nearPlane) {
	near = nearPlane;
}

void Camera::SetFarPlane (double farPlane) {
	far = farPlane;
}

void Camera::SetScreenSize (int screenWidth, int screenHeight) {
	ekranWidth = screenWidth;
	ekranHeight = screenHeight;
}

Matrix Camera::GetModelViewMatrix() {
	Vector w = -lookVec/length(lookVec);
	Vector u = cross(upVec,w)/length(cross(upVec, w));
	Vector v = cross(w,u);
	Matrix rotationMat = Matrix(u[0], u[1], u[2], 0, v[0], v[1], v[2], 0, w[0], w[1], w[2], 0, 0, 0, 0, 1);
	Matrix transformationMat = Matrix(1, 0, 0, -eyePt[0], 0, 1, 0, -eyePt[1], 0, 0, 1, -eyePt[2], 0, 0, 0, 1);
	return rotationMat * transformationMat;
}

void Camera::RotateV(double angle) {
	Vector w = -lookVec/length(lookVec);
	Vector u = cross(upVec,w)/length(cross(upVec, w));
	Vector v = cross(w,u);
	Matrix rotMat = rot_mat(v, DEG_TO_RAD(angle));
	lookVec = rotMat * lookVec;
	upVec = rotMat * upVec;
}

void Camera::RotateU(double angle) {
	Vector w = -lookVec/length(lookVec);
	Vector u = cross(upVec,w)/length(cross(upVec, w));
	Matrix rotMat = rot_mat(u, DEG_TO_RAD(angle));
	lookVec = rotMat * lookVec;
	upVec = rotMat * upVec;
}

void Camera::RotateW(double angle) {
	Vector w = -lookVec/length(lookVec);
	Matrix rotMat = rot_mat(w, DEG_TO_RAD(angle));
	lookVec = rotMat * lookVec;
	upVec = rotMat * upVec;
}

void Camera::Translate(const Vector &v) {
	Matrix transformationMat = Matrix(1, 0, 0, v[0], 0, 1, 0, v[1], 0, 0, 1, v[2], 0, 0, 0, 1);
	eyePt = transformationMat * eyePt;
}


void Camera::Rotate(Point p, Vector axis, double degrees) {
	double yangle = atan(axis[2] / axis[0]);
	double phi = acos(axis[1] / sqrt(length(axis)));
	Matrix M1 = rotY_mat(yangle);
	Matrix M1I = rotY_mat(-yangle);
	Matrix M2 = rotZ_mat(-phi - PI / 2);
	Matrix M2I = rotZ_mat(phi - PI / 2);
	Matrix M3 = rotX_mat(DEG_TO_RAD(degrees));
	p = M1I *M2I*M3*M2*M1 * p;
}


Point Camera::GetEyePoint() {
	return eyePt;
}

Vector Camera::GetLookVector() {
	return lookVec;
}

Vector Camera::GetUpVector() {
	return upVec;
}

double Camera::GetViewAngle() {
	return viewAng;
}

double Camera::GetNearPlane() {
	return near;
}

double Camera::GetFarPlane() {
	return far;
}

int Camera::GetScreenWidth() {
	return ekranWidth;
}

int Camera::GetScreenHeight() {
	return ekranHeight;
}

double Camera::GetFilmPlaneDepth() {
	return filmPlaneDepth;
}

double Camera::GetScreenWidthRatio() {
	return (float)ekranWidth/(float)ekranHeight;
}
