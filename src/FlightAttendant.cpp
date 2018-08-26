#include "FlightAttendant.hpp"

FlightAttendant::FlightAttendant(const std::string &name, int id) :
		Employee(name, id), spokenLanguages() {
}

void FlightAttendant::addLanguage(Country::Language language) {
	spokenLanguages.push_back(language);
}

bool FlightAttendant::canSpeak(Country::Language language) const {
	for (unsigned int i = 0; i < spokenLanguages.size(); i++) {
		Country::Language currentLanguage = spokenLanguages[i];
		if (currentLanguage == language) {
			return true;
		}
	}
	return false;
}

FlightAttendant::~FlightAttendant() {
}
