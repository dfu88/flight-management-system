#include "Customer.hpp"

Customer::Customer(const std::string &name, const std::string &passportNumber) :
		Human(name), passportNumber(passportNumber), points(0){
}

void Customer::addLoyaltyPoints(int points){
	this->points += points;
}

void Customer::decreaseLoyaltyPoints(int points){
	this->points -= points;
	if (this->points < 0) {
		this->points = 0;
	}
}

int Customer::getLoyaltyPoints() const{
	return points;
}

std::string Customer::getPassportNumber() const{
	return passportNumber;
}

Customer::~Customer() {
}
