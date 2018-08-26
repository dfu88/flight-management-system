#ifndef AIRPLANE_HPP
#define AIRPLANE_HPP

class Airplane {
private:
	const unsigned int capacity;
    Airplane& operator=(const Airplane &other);
    Airplane(const Airplane &other);
public:
    Airplane(unsigned int capacity);
    int getCapacity() const;
    ~Airplane();
};

#endif
