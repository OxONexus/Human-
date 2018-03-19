#include "Bone.hpp"

Bone::Bone(void) {

}


Bone::Bone(Vec3 pos) {
	_pos = get_trans(pos);
}

Bone::Bone(Bone const & src) {
	*this = src;
}

Bone::~Bone(void) {

}


Bone &Bone::operator=(Bone const & rhs) {
	if (this != &rhs){

	}
	return (*this);
}
