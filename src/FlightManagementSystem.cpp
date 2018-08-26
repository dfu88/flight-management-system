#include "FlightManagementSystem.hpp"

FlightManagementSystem::FlightManagementSystem() :
		customers(), flights(), times() {
}

std::string FlightManagementSystem::author() {
	return "dfu987";
}

bool FlightManagementSystem::addCustomer(Customer *customer){
	if (FlightManagementSystem::checkCustomerPassportNumber(customer->getPassportNumber())){
		return false;
	} else {
		customers.push_back(customer);
		return true;
	}
}

void FlightManagementSystem::addCustomerPoints(const std::string &passportNumber, int points) {
	for (unsigned int i = 0; i < customers.size(); i++){
		if (customers[i]->getPassportNumber() == passportNumber){
			customers[i]->addLoyaltyPoints(points);
		}
	}
}

void FlightManagementSystem::addFlight(Flight* flight, Date* time){
	flights.push_back(flight);
	times.push_back(time);
}

/*
 * FlightManagementSystem::bookTicket:
 *	Checks that the customer exists in the flight management system.
 *	Then checks for a flight equivalent to route and time provided,
 *	if found then book tickets and gives loyalty points to customer,
 */
bool FlightManagementSystem::bookTicket(Route* route, Date *time, const std::string &passportNumber, int quantity){
	if (FlightManagementSystem::checkCustomerPassportNumber(passportNumber)){
		int flightIndex = FlightManagementSystem::matchingFlightIndex(route, time);
		if (flightIndex >= 0) {
			if (flights[flightIndex]->bookTicket(quantity)){
				int points = (flights[flightIndex]->getRoute()->getHours()*quantity);
				FlightManagementSystem::addCustomerPoints(passportNumber, points);
				return true;
			}
		}
	}
	return false;
}

bool FlightManagementSystem::checkCustomerPassportNumber(const std::string &passportNumber) const{
	for (unsigned int i = 0; i < customers.size(); i++){
		if (customers[i]->getPassportNumber() == passportNumber){
			return true;
		}
	}
	return false;
}

/*
 * FlightManagementSystem::matchingFlightIndex:
 * 	Checks for equivalent flight by checking the 'flights'
 * 	and 'times' vectors for matching source, destination, time (day and hour).
 * 	Doesn't consider distance in hours, so it can find equivalent flights.
 */
int FlightManagementSystem::matchingFlightIndex(const Route * route, const Date * time) const{
	for (unsigned int index = 0; index < flights.size(); index++){
		if ((flights[index]->getRoute()->getSource() == route->getSource())
				&& (flights[index]->getRoute()->getDestination() == route->getDestination())
				&& (times[index]->getDay() == time->getDay())
				&& (times[index]->getHour() == time->getHour())){
			return index;
		}
	}
	return -1;
}

int FlightManagementSystem::getCapacity(const Route* route, const Date* time) const{
	int flightIndex = FlightManagementSystem::matchingFlightIndex(route, time);
	if (flightIndex >= 0) {
		return flights[flightIndex]->getAvailableSeats();
	}
	return -1;
}

int FlightManagementSystem::getCustomerPoints(const std::string &passportNumber) const{
	for (unsigned int i = 0; i < customers.size(); i++){
		if (customers[i]->getPassportNumber() == passportNumber){
			return customers[i]->getLoyaltyPoints();
		}
	}
	return -1;
}

std::vector<Customer *> FlightManagementSystem::getCustomers() const{
	return customers;
}

std::vector<Flight *> FlightManagementSystem::getFlights() const{
	return flights;
}

std::vector<Date *> FlightManagementSystem::getTimes() const{
	return times;
}

FlightManagementSystem::~FlightManagementSystem(){
	//	Goes through the 'Customer', 'Flight', 'Date' vectors
	//	and deletes the instances from the heap
	for (std::vector<Customer *>::iterator it = customers.begin(); it != customers.end(); ++it){
		delete (*it);
	}
	for (std::vector<Flight *>::iterator it = flights.begin(); it != flights.end(); ++it){
		delete (*it);
		*it = NULL;
	}
	for (std::vector<Date *>::iterator it = times.begin(); it != times.end(); ++it){
		delete (*it);
	}
}

