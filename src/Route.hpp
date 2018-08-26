#ifndef ROUTE_HPP
#define ROUTE_HPP

#include "Country.hpp"

class Route{
private:
    Route& operator=(const Route& other);
    Route(const Route& other);
    Country* source;
	Country* destination;
	unsigned int hours;
public:
    Route(Country *source, Country *destination, int hours);
    Country* getSource() const;
    Country* getDestination() const;
    int getHours() const;
    ~Route();
};

#endif
