#ifndef FLIGHT_HPP
#define FLIGHT_HPP

#include "Pilot.hpp"
#include "Route.hpp"
#include "FlightAttendant.hpp"
#include "Airplane.hpp"
#include "Date.hpp"

class Flight{
private:
	Flight& operator=(const Flight& other);
	Flight(const Flight& other);
	Route *route;
	Airplane *airplane;
	int availableSeats;
	std::vector<Pilot *> assignedPilots;
	std::vector<FlightAttendant *> assignedFlightAttendants;
	unsigned int numOfPilotsNeeded;
	unsigned int numOfFlightAttendantsNeeded;
	std::vector<Country::Language> languagesNeeded;
public:
    Flight(Route *route, Airplane* airplane);
    bool setFlightAttendants(std::vector<FlightAttendant*> flightAttendants);
    bool setPilots(std::vector<Pilot*> pilots);
    bool bookTicket(int quantity);
    int getAvailableSeats() const;
    Route* getRoute() const;
    Airplane* getAirplane() const;
    std::vector<Pilot *> getPilots() const;
    std::vector<FlightAttendant *> getFlightAttendants() const;
    ~Flight();
};

#endif
