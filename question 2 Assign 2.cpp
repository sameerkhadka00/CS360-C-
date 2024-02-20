#include <iostream>

class Date {
public:
    Date(int m, int d, int y); 
    void setMonth(int m); 
    void setDay(int d); 
    void setYear(int y); 
    int getMonth() const; 
    int getDay() const; 
    int getYear() const; 
    void displayDate() const; 
private:
    int month; 
    int day; 
    int year; 
};


Date::Date(int m, int d, int y) {
    setMonth(m);
    setDay(d);
    setYear(y);
}


void Date::setMonth(int m) {
    month = (m >= 1 && m <= 12) ? m : 1;
}


void Date::setDay(int d) {
    day = d;
}


void Date::setYear(int y) {
    year = y;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

int Date::getYear() const {
    return year;
}

void Date::displayDate() const {
    std::cout << month << "/" << day << "/" << year << std::endl;
}

int main() {
    Date myDate(2, 20, 2024);

    std::cout << "Initial date: ";
    myDate.displayDate();

    myDate.setMonth(12);
    myDate.setDay(31);
    myDate.setYear(2025);

    std::cout << "Updated date: ";
    myDate.displayDate();

    return 0;
}
