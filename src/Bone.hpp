#pragma once

#include "Human.hpp"

class Bone {
	public:
		Bone(void);
		Bone(Vec3 pos);
		Bone(Bone const & src);
		virtual ~Bone(void);
		Bone & operator=(Bone const & rhs);
	private:
		Matrix _rot;
		Matrix _pos;
		Matrix _scale;
};
