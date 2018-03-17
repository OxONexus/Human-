#include "Charactere.hpp"

Charactere::Charactere(): _pos(0, 0, 0) {
	_root = nullptr;
}
Charactere::Charactere(Vec3 pos): _pos(pos) {
	_root = nullptr;
}
Charactere::~Charactere() {}

Charactere::Charactere(const Charactere &src) {
	*this = src;
}

Charactere &Charactere::operator=(const Charactere &a) {
	if (this != &a) {
		
	}
	return *this;
}
