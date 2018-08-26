
#include "Country.hpp"

Country::Country(const std::string &name, Language language) :
		name(name), language(language){
}

Country::Language Country::getLanguage() const{
    return language;
}

std::string Country::getName() const{
    return name;
}

Country::~Country(){
}
