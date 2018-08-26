#ifndef TIME_HPP
#define TIME_HPP

class Date{
private:
	int day, hour;
	Date& operator=(const Date& other);
	Date(const Date& other);
public:
    Date(int day, int hour);
    int getDay() const;
    int getHour() const;
    void addTime(int hours);
    bool isLessThan(const Date &other) const;
    void changeDateTo(int day, int hour);
    ~Date();
};

#endif /* end of include guard: TIME_HPP */
