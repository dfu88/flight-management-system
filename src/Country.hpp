#ifndef COUNTRY_HPP
#define COUNTRY_HPP

#include <string>

class Country {
public:
    enum Language {
        CHINESE,
        SPANISH,
        ENGLISH,
        HINDI,
        ARABIC
    };
    Country(const std::string &name, Language language);
    Language getLanguage() const;
    std::string getName() const;
    ~Country();
private:
    const std::string name;
    const Language language;
    Country(const Country &other);
    Country& operator=(const Country &other);
};

#endif
