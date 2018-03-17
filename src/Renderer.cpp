#include "Renderer.hpp"

Renderer::Renderer(void) {

		std::vector<GLfloat> cube_strip = {
		-1.f, 1.f, 1.f,
		1.f, 1.f, 1.f,  
		-1.f, -1.f, 1.f,
		1.f, -1.f, 1.f, 
		1.f, -1.f, -1.f,
		1.f, 1.f, 1.f, 
		1.f, 1.f, -1.f,
		-1.f, 1.f, 1.f,
		-1.f, 1.f, -1.f, 
		-1.f, -1.f, 1.f,   
		-1.f, -1.f, -1.f,  
		1.f, -1.f, -1.f,  
		-1.f, 1.f, -1.f, 
		1.f, 1.f, -1.f   
	};
	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);

	glGenBuffers(1, &_vbo_bone_id);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo_bone_id);
	glBufferData(_vbo_bone_id, sizeof(float) * cube_strip.size(), &cube_strip[0], GL_STATIC_DRAW);
}

Renderer::Renderer(Renderer const & src) {
	*this = src;
}

Renderer::~Renderer(void) {

}

Renderer &	Renderer::operator=(Renderer const & rhs) {
	if (this != &rhs){

	}
	return (*this);
}
