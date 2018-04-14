#include "Renderer.hpp"
Renderer::Renderer(Env &env) : _shader("human.vert", "human.frag"),
							   _cam(Vec3(0.0, 0.0, -1.0), Vec3(0.0, 0.0, 0.0), env.width, env.height) {

static const GLfloat cube_strip[] = {
    -1.f, 1.f, 1.f,     // Front-top-left
    1.f, 1.f, 1.f,      // Front-top-right
    -1.f, -1.f, 1.f,    // Front-bottom-left
    1.f, -1.f, 1.f,     // Front-bottom-right
    1.f, -1.f, -1.f,    // Back-bottom-right
    1.f, 1.f, 1.f,      // Front-top-right
    1.f, 1.f, -1.f,     // Back-top-right
    -1.f, 1.f, 1.f,     // Front-top-left
    -1.f, 1.f, -1.f,    // Back-top-left
    -1.f, -1.f, 1.f,    // Front-bottom-left
    -1.f, -1.f, -1.f,   // Back-bottom-left
    1.f, -1.f, -1.f,    // Back-bottom-right
    -1.f, 1.f, -1.f,    // Back-top-left
    1.f, 1.f, -1.f      // Back-top-right
};
	/*float cube_strip[9] = {
			1.f, 0.f, 0.f,
			0.f, 1.f, 0.f,
			0.f, 0.f, 1.f
	};*/
	glGenBuffers(1, &_vbo_bone_id);
	glGenVertexArrays(1, &_vao);

	glBindVertexArray(_vao);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo_bone_id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube_strip), cube_strip, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, 0, 3 * sizeof(float), NULL);
	glEnableVertexAttribArray(0);

	Charactere test(Vec3(0, 0, 0), "asset/simple.bvh");
	_array_Charactere.push_back(test);
	_shader.use();
	
}

void Renderer::updateUniform() {
	GLint _mvp_loca = glGetUniformLocation(_shader.id, "PV")	;
	Matrix mv = _cam.view * _cam.proj;
	glUniformMatrix4fv(_mvp_loca, 1, 0, &mv.mat4[0]);
}


Renderer::Renderer(Renderer const & src) : _shader("human.vert", "human.frag"){
	*this = src;
}

Renderer::~Renderer(void) {

}

Renderer &Renderer::operator=(Renderer const & rhs) {
	if (this != &rhs){

	}
	return (*this);
}

void Renderer::update(Env &env) {
	_cam.update(env);
	updateUniform();
	for (auto && charactere : _array_Charactere) {
		charactere.update();
	}
	draw(env);
}

void Renderer::draw_bones(Env &env, Bone *bone, Matrix transform) {
	Matrix iden = bone->get_model();
	glUniformMatrix4fv(glGetUniformLocation(_shader.id, "M"), 1, 0, &iden.mat4[0]);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 42);
	std::vector<Bone> *child = bone->get_child();
	for (int i = 0; i < (*child)->size(); ++i) {
		std::cout << "coucou"  << std::endl;
	}
}

void Renderer::draw_characteres(Env &env) {
	for (int i = 0; i < _array_Charactere.size(); ++i) {
		draw_bones(env, _array_Charactere[i].get_bones(), _array_Charactere[i].get_model());
	}
}

void Renderer::draw(Env &env) {
	Matrix iden;
	_shader.use();
	iden.get_identity();
	glUniformMatrix4fv(glGetUniformLocation(_shader.id, "M"), 1, 0, &iden.mat4[0]);
	glBindVertexArray(_vao);
	draw_characteres(env);
}
