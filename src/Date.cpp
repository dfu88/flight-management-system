#include "Date.hpp"

Date::Date(int day, int hour){
	if (day>=1){
		this->day = day;
	} else {
		this->day = 1;
	}

	if (hour>=0 && hour<=23){
		this->hour = hour;
	} else {
		this->hour = 0;
	}
	int addDay = (hour)/24;
	int addHour = (hour)%24;
	this->day += addDay;
	this->hour = addHour;
}

int Date::getHour() const{
    return hour;
}

int Date::getDay() const{
	return day;
}

void Date::changeDateTo(int day, int hour){
	if (day>=1 && hour>=0 && hour<=23){
		this->day = day;
		this->hour = hour;
	}
}

void Date::addTime(int count){
	if (count > 0){
		int addDay = (hour+count)/24;
		int addHour = (hour+count)%24;
		day += addDay;
		hour = addHour;
	}
}

bool Date::isLessThan(const Date &other) const{
	if (day < other.day){
		return true;
	} else if (day == other.day){
		if (hour<other.hour){
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}

Date::~Date(){}
