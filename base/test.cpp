#include "test.h"

test::test() {
	this->_windowTitle = std::string("test window title");

	camera.reset(new PerspectiveCamera(glm::radians(45.0f), 1.0f * _windowWidth / _windowHeight, 0.1f, 10000.0f));
	camera->position.z = 50.0f;

	test_shader.reset(new Shader(
		std::string("D:/2021WinterMaterial/Graphics/CG_proj/shader/test_vertex_shader.txt"),
		std::string("D:/2021WinterMaterial/Graphics/CG_proj/shader/test_frag_shader.txt")
		));

	tmp_model.reset(new Model("D:/2021WinterMaterial/Graphics/CG_proj/data/nanosuit_model/nanosuit.obj"));
}


void test::handleInput() {
	return;
}

void test::renderFrame() {
	showFpsInWindowTitle();

	glClearColor(_clearColor.r, _clearColor.g, _clearColor.b, _clearColor.a);
	glClear(GL_COLOR_BUFFER_BIT);


	glm::mat4 projection = camera->getProjectionMatrix();
	glm::mat4 view = camera->getViewMatrix();

	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
	model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));	// it's a bit too big for our scene, so scale it down

	test_shader->use();
	test_shader->setMat4("projection", projection);
	test_shader->setMat4("view", view);
	test_shader->setMat4("model", model);

	tmp_model->Draw(*test_shader);
}
