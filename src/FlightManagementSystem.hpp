#ifndef FLIGHTMANAGEMENTSYSTEM_HPP
#define FLIGHTMANAGEMENTSYSTEM_HPP

#include "Flight.hpp"
#include "Customer.hpp"

class FlightManagementSystem {
private:
	FlightManagementSystem& operator=(const FlightManagementSystem& other);
	FlightManagementSystem(const FlightManagementSystem& other);
	std::vector<Customer *> customers;
	std::vector<Flight *> flights;
	std::vector<Date *> times;
	bool checkCustomerPassportNumber(const std::string &passportNumber) const;
	int matchingFlightIndex(const Route* route, const Date *time) const;
public:
	FlightManagementSystem();
	static std::string author();
	bool addCustomer(Customer* customer);
	void addCustomerPoints(const std::string &passportNumber, int points);
	void addFlight(Flight* flight, Date* time);
	bool bookTicket(Route* route, Date* time, const std::string &passportNumber, int quantity);

	int getCapacity(const Route* route, const Date* time) const;
	int getCustomerPoints(const std::string &passportNumber) const;
	std::vector<Customer *> getCustomers() const;
	std::vector<Flight *> getFlights() const;
	std::vector<Date *> getTimes() const;
	~FlightManagementSystem();
};

#endif
