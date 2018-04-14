#pragma once

#include "Charactere.hpp"
#include "shader.hpp"
#include "Camera.h"

class Renderer {
	public:
		Renderer(Env &env);
		Renderer(Renderer const & src);
		virtual ~Renderer(void);
		Renderer & operator=(Renderer const & rhs);
		void updateUniform();
		void update( Env &env);
		void draw(Env &env);
		void draw_bones(Env &env, Bone *bone, Matrix trnasform);
		void draw_characteres(Env &env);
	private:
		std::vector<Charactere> _array_Charactere = {};
		GLuint _vbo_bone_id;
		GLuint _vao;
		Shader _shader;
		Camera _cam;
};
