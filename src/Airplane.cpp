#include "Airplane.hpp"

Airplane::Airplane(const unsigned int capacity) :
		capacity(capacity){
}

int Airplane::getCapacity() const{
	return capacity;
}

Airplane::~Airplane(){
}
