#ifndef PILOT_HPP
#define PILOT_HPP

#include "Employee.hpp"

class Pilot : public Employee {
public:
    enum Level {
        CAPTAIN = 0,
        CO_PILOT
    };

    Pilot(const std::string &name, int ID);
    bool promote();
    bool demote();
    Level getLevel() const;
    virtual ~Pilot();
private:
    Pilot& operator=(const Pilot& other);
    Pilot(const Pilot& other);
    Level level;
};

#endif
