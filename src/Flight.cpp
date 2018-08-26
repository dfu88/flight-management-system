#include "Flight.hpp"

#include <algorithm>

Flight::Flight(Route *route, Airplane* airplane) :
		route(route), airplane(airplane), assignedPilots(), assignedFlightAttendants(){
	if (route->getHours() < 8){
		// For short haul flight
		numOfPilotsNeeded = 2;
		numOfFlightAttendantsNeeded = 3;
		availableSeats = (airplane->getCapacity() - 3);
	} else {
		// For long haul flight
		numOfPilotsNeeded = 4;
		numOfFlightAttendantsNeeded = 6;
		availableSeats = (airplane->getCapacity() - 8);
	}
	// Stores destination language for comparisons
	languagesNeeded.push_back(route->getDestination()->getLanguage());
	// Stores source language for comparisons
	languagesNeeded.push_back(route->getSource()->getLanguage());
}

/*
 * Flight::setPilots:
 * 	Checking for the correct number of pilots provided,
 * 	two or four pilots considering short or long haul flights
 * 	and that half are captains and the other half are co-pilots
 */
bool Flight::setPilots(std::vector<Pilot*> pilots){
	if (numOfPilotsNeeded == pilots.size() && assignedPilots.empty()){
		unsigned int CapCount = 0, CoCount = 0, divisor =2;
		for (unsigned int i = 0; i < pilots.size(); i++){
			if (pilots[i]->getLevel() == Pilot::CAPTAIN){
				CapCount++;
			}
			if (pilots[i]->getLevel() == Pilot::CO_PILOT){
				CoCount++;
			}
			if ((CapCount==pilots.size()/divisor) && (CoCount==(pilots.size()/divisor))){
				assignedPilots = pilots;
				return true;
			}
		}
		return false;
	} else {
		return false;
	}
}

/*
 * Flight::setFlightAttendants:
 * 	Checks that no flight attendants have been assigned.
 * 	For SHORT HAUL flights we check for 3 flight attendants provided.
 * 	At least one flight attendant for English, source, destination
 * 	language, met by three different flight attendants.
 * 	For LONG HAUL flights we check for 6 flight attendants provided.
 * 	At least two unique flight attendants for English, source and
 * 	destination language, doesn't need all six to contribute.
 */
bool Flight::setFlightAttendants(std::vector<FlightAttendant *> flightAttendants){
	if ((numOfFlightAttendantsNeeded == flightAttendants.size()) && assignedFlightAttendants.empty()) {
		// Checks for languages needed in a short haul flight
		if (numOfFlightAttendantsNeeded == 3){
			for (unsigned int i = 0; i < 3; i++){
				for (unsigned int j = 1; j < 3; j++){
					std::swap(flightAttendants[0],flightAttendants[j]);
					if ((flightAttendants[0]->canSpeak(Country::ENGLISH))
							&& (flightAttendants[1]->canSpeak(
									languagesNeeded[0]))
							&& (flightAttendants[2]->canSpeak(
									languagesNeeded[1]))) {
						assignedFlightAttendants = flightAttendants;
						return true;
					}
				}
			}
		}
		// Checks for languages needed in a long haul flight
		if (numOfFlightAttendantsNeeded == 6){
			int englishCount = 0; int sourceCount = 0; int destinationCount = 0;
			for (unsigned int i = 0; i < 6; i++){
				if (flightAttendants[i]->canSpeak(Country::ENGLISH)){
					englishCount++;
				}
				if (flightAttendants[i]->canSpeak(languagesNeeded[0])){
					sourceCount++;
				}
				if (flightAttendants[i]->canSpeak(languagesNeeded[1])){
					destinationCount++;
				}
				if ((englishCount >= 2) && (sourceCount >= 2) && (destinationCount >= 2)){
					assignedFlightAttendants = flightAttendants;
					return true;
				}
			}
		}
	}
	return false;
}

bool Flight::bookTicket(int quantity){
	if (availableSeats >= quantity){
		availableSeats -= quantity;
		return true;
	} else {
		return false;
	}
}

int Flight::getAvailableSeats() const{
	return availableSeats;
}

Route* Flight::getRoute() const{
	return route;
}

Airplane* Flight::getAirplane() const{
	return airplane;
}

std::vector<Pilot *> Flight::getPilots() const{
	return assignedPilots;
}

std::vector<FlightAttendant *> Flight::getFlightAttendants() const{
	return assignedFlightAttendants;
}

Flight::~Flight(){
	delete route;
	delete airplane;

	//	Goes through the 'assignedPilots', 'assignedFlightAttendants' vectors
	//	and deletes the instances from the heap
	for (std::vector<Pilot *>::iterator it = assignedPilots.begin(); it != assignedPilots.end(); ++it){
		delete (*it);
	}
	for (std::vector<FlightAttendant *>::iterator it = assignedFlightAttendants.begin(); it != assignedFlightAttendants.end(); ++it){
		delete (*it);
	}
}
