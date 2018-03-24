#pragma once

#include "Human.hpp"

class Bone {
	public:
		Bone(void);
		Bone(Vec3 pos, std::string filename);
		Bone(std::string name);
		Bone(Bone const & src);
		virtual ~Bone(void);
		Bone & operator=(Bone const & rhs);
		void read_bvhfile(std::string filename);
		void setPos(Vec3 pos);
		Bone* append_child(std::string name);
	private:
		Matrix _rot;
		Matrix _pos;
		Matrix _scale;
		std::string _name;
		std::vector<Bone> _child = {};
};

enum TYPE {xpos = 0, ypos = 1, zpos = 2, xrot = 3, yrot = 4, zrot = 5, xscl = 6, yscl = 7, zscl = 8};

typedef struct MotionInfo {
	enum TYPE type;
	Bone *bone;
} m_info;

