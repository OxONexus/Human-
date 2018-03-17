#pragma once

#include "Charactere.hpp"
#include "env.hpp"

class Renderer {
	public:
		Renderer(void);
		Renderer(Renderer const & src);
		virtual ~Renderer(void);
		Renderer & operator=(Renderer const & rhs);
	private:
		std::vector<Charactere> _array_Charactere = {};
		GLuint _vbo_bone_id;
		GLuint _vao;
};
