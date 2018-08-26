
#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include "Human.hpp"

class Employee : public Human {
private:
    Employee& operator=(const Employee& other);
    Employee(const Employee& other);
protected:
    int id;
public:
    Employee(const std::string &name, int id);
    virtual int getID() const;
    virtual ~Employee();
};

#endif
