#include "Employee.hpp"

Employee::Employee(const std::string &name, int id) :
		Human(name), id(id) {
}

int Employee::getID() const {
	return id;
}

Employee::~Employee() {
}
