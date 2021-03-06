#pragma once
#include "../../base/object3d.h"
#include "../../base/material.h"
#include "../../base/shader.h"
#include "../../base/collision.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>


class Square_pyramid : public Object3D {
public:
    Square_pyramid();
    ~Square_pyramid();

    void Draw(Shader& shader);

    inline void SetKa(glm::vec4 ka) { mat.Ka = ka; }
    inline void SetKd(glm::vec4 kd) { mat.Kd = kd; }
    inline void SetKs(glm::vec4 ks) { mat.Ks = ks; }
    inline void SetShiniess(float shininess) { mat.shininess = shininess; }

    AABB collision;

private:
    // notice that the normal data hasn't been set

    struct Material mat;

    GLuint vao, vbo;
    float vertices[216] = {
        //0.95  0.32
        -1.0f, -1.0f, -1.0f,  0.0f,  0.33f, -1.0f,
         1.0f, -1.0f, -1.0f,  0.0f,  0.33f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.33f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.33f, -1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.33f, -1.0f,
        -1.0f, -1.0f, -1.0f,  0.0f,  0.33f, -1.0f,

        -1.0f, -1.0f,  1.0f,  0.0f,  0.33f,  1.0f,
         1.0f, -1.0f,  1.0f,  0.0f,  0.33f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.33f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.33f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.33f,  1.0f,
        -1.0f, -1.0f,  1.0f,  0.0f,  0.33f,  1.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.33f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.33f,  0.0f,
        -1.0f, -1.0f, -1.0f, -1.0f,  0.33f,  0.0f,
        -1.0f, -1.0f, -1.0f, -1.0f,  0.33f,  0.0f,
        -1.0f, -1.0f,  1.0f, -1.0f,  0.33f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.33f,  0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.33f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.33f,  0.0f,
         1.0f, -1.0f, -1.0f,  1.0f,  0.33f,  0.0f,
         1.0f, -1.0f, -1.0f,  1.0f,  0.33f,  0.0f,
         1.0f, -1.0f,  1.0f,  1.0f,  0.33f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.33f,  0.0f,

        -1.0f, -1.0f, -1.0f,  0.0f, -1.0f,  0.0f,
         1.0f, -1.0f, -1.0f,  0.0f, -1.0f,  0.0f,
         1.0f, -1.0f,  1.0f,  0.0f, -1.0f,  0.0f,
         1.0f, -1.0f,  1.0f,  0.0f, -1.0f,  0.0f,
        -1.0f, -1.0f,  1.0f,  0.0f, -1.0f,  0.0f,
        -1.0f, -1.0f, -1.0f,  0.0f, -1.0f,  0.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
    };
    
};
