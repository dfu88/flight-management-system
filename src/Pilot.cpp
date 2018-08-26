#include "Pilot.hpp"

Pilot::Pilot(const std::string &name, int id) :
		Employee(name, id), level(CO_PILOT) {
}

bool Pilot::promote() {
	if (level == CO_PILOT) {
		level = CAPTAIN;
		return true;
	} else {
		return false;
	}
}

bool Pilot::demote() {
	if (level == CAPTAIN) {
		level = CO_PILOT;
		return true;
	} else {
		return false;
	}
}

Pilot::Level Pilot::getLevel() const {
	return level;
}

Pilot::~Pilot() {
}
