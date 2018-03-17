#pragma once

#include "Human.hpp"
#include "Bone.hpp"

class Charactere {
	public :
		Charactere();
		Charactere(const Charactere &b);
		Charactere(Vec3 pos);
		~Charactere();
		Charactere &operator=(const Charactere &a);
	private :
		Vec3 _pos;
		Bone *_root;
};
