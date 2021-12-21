#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

struct Material {
    //������ɫ����
    glm::vec4 Ka;
    //������
    glm::vec4 Kd;
    //������
    glm::vec4 Ks;
    float shininess;
};
