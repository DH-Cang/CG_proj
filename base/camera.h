#pragma once

#include "object3d.h"

#include <chrono>
#include <string>
#include <stdexcept>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "input.h"
#include "shader.h"

class Camera : public Object3D {
public:
	glm::mat4 getViewMatrix() const;

	virtual glm::mat4 getProjectionMatrix() const = 0;

protected:

	/* input handler */
	KeyboardInput _keyboardInput;
	MouseInput _mouseInput;
};


class PerspectiveCamera : public Camera {
public:
	float fovy;	//�ӽ�
	float aspect;	// ��߱�
	float znear;	// ��ƽ�����
	float zfar;		// Զƽ�����
public:
	PerspectiveCamera(float fovy, float aspect, float znear, float zfar);

	~PerspectiveCamera() = default;

	glm::mat4 getProjectionMatrix() const override;
};


class OrthographicCamera : public Camera {
public:
	float left;
	float right;
	float bottom;
	float top;
	float znear;
	float zfar;
public:
	OrthographicCamera(float left, float right, float bottom, float top, float znear, float zfar);
	
	~OrthographicCamera() = default;

	glm::mat4 getProjectionMatrix() const override;
};