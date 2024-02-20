#include <iostream>
#include <string>

class HeartRates {
public:
    HeartRates(std::string fName, std::string lName, int birthMonth, int birthDay, int birthYear);
    
    void setFirstName(std::string fName);
    std::string getFirstName() const;
    
    void setLastName(std::string lName);
    std::string getLastName() const;
    
    void setBirthMonth(int month);
    int getBirthMonth() const;
    
    void setBirthDay(int day);
    int getBirthDay() const;
    
    void setBirthYear(int year);
    int getBirthYear() const;
    
    int getAge(int currentMonth, int currentDay, int currentYear) const;
    int getMaximumHeartRate(int currentMonth, int currentDay, int currentYear) const;
    std::pair<int, int> getTargetHeartRate(int currentMonth, int currentDay, int currentYear) const;
    
private:
    std::string firstName;
    std::string lastName;
    int birthMonth;
    int birthDay;
    int birthYear;
};

HeartRates::HeartRates(std::string fName, std::string lName, int birthMonth, int birthDay, int birthYear)
    : firstName(fName), lastName(lName), birthMonth(birthMonth), birthDay(birthDay), birthYear(birthYear) {}

void HeartRates::setFirstName(std::string fName) {
    firstName = fName;
}

std::string HeartRates::getFirstName() const {
    return firstName;
}

void HeartRates::setLastName(std::string lName) {
    lastName = lName;
}

std::string HeartRates::getLastName() const {
    return lastName;
}

void HeartRates::setBirthMonth(int month) {
    birthMonth = month;
}

int HeartRates::getBirthMonth() const {
    return birthMonth;
}

void HeartRates::setBirthDay(int day) {
    birthDay = day;
}

int HeartRates::getBirthDay() const {
    return birthDay;
}

void HeartRates::setBirthYear(int year) {
    birthYear = year;
}

int HeartRates::getBirthYear() const {
    return birthYear;
}

int HeartRates::getAge(int currentMonth, int currentDay, int currentYear) const {
    int age = currentYear - birthYear;
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
        age--;
    }
    return age;
}

int HeartRates::getMaximumHeartRate(int currentMonth, int currentDay, int currentYear) const {
    return 220 - getAge(currentMonth, currentDay, currentYear);
}

std::pair<int, int> HeartRates::getTargetHeartRate(int currentMonth, int currentDay, int currentYear) const {
    int maxHeartRate = getMaximumHeartRate(currentMonth, currentDay, currentYear);
    int minTarget = maxHeartRate * 0.5;
    int maxTarget = maxHeartRate * 0.85;
    return std::make_pair(minTarget, maxTarget);
}

int main() {
    std::string firstName, lastName;
    int birthMonth, birthDay, birthYear;
    
    std::cout << "Enter first name: ";
    std::cin >> firstName;
    
    std::cout << "Enter last name: ";
    std::cin >> lastName;
    
    std::cout << "Enter birth month (1-12): ";
    std::cin >> birthMonth;
    
    std::cout << "Enter birth day: ";
    std::cin >> birthDay;
    
    std::cout << "Enter birth year: ";
    std::cin >> birthYear;
    
    HeartRates person(firstName, lastName, birthMonth, birthDay, birthYear);
    
    int currentMonth, currentDay, currentYear;
    std::cout << "Enter current month (1-12): ";
    std::cin >> currentMonth;
    
    std::cout << "Enter current day: ";
    std::cin >> currentDay;
    
    std::cout << "Enter current year: ";
    std::cin >> currentYear;
    
    std::cout << "\nInformation:\n";
    std::cout << "Name: " << person.getFirstName() << " " << person.getLastName() << std::endl;
    std::cout << "Date of Birth: " << person.getBirthMonth() << "/" << person.getBirthDay() << "/" << person.getBirthYear() << std::endl;
    std::cout << "Age: " << person.getAge(currentMonth, currentDay, currentYear) << " years" << std::endl;
    
    int maxHeartRate = person.getMaximumHeartRate(currentMonth, currentDay, currentYear);
    std::cout << "Maximum Heart Rate: " << maxHeartRate << " bpm" << std::endl;
    
    auto targetHeartRate = person.getTargetHeartRate(currentMonth, currentDay, currentYear);
    std::cout << "Target Heart Rate Range: " << targetHeartRate.first << " bpm - " << targetHeartRate.second << " bpm" << std::endl;
    
    return 0;
}
