#include <iostream>
#include <string>

class GradeBook {
public:
    explicit GradeBook(std::string, std::string); 
    void setCourseName(std::string); 
    void setInstructorName(std::string); 
    std::string getCourseName() const; 
    std::string getInstructorName() const; 
    void displayMessage() const; 
private:
    std::string courseName; 
    std::string instructorName; 
};

GradeBook::GradeBook(std::string course, std::string instructor)
    : courseName(course), instructorName(instructor) {}

void GradeBook::setCourseName(std::string name) {
    courseName = name;
}

void GradeBook::setInstructorName(std::string name) {
    instructorName = name;
}

std::string GradeBook::getCourseName() const {
    return courseName;
}

std::string GradeBook::getInstructorName() const {
    return instructorName;
}

void GradeBook::displayMessage() const {
    std::cout << "Welcome to the grade book for\n" << getCourseName()
              << "!\nThis course is presented by: " << getInstructorName()
              << std::endl;
}

int main() {
    GradeBook myGradeBook("C++ Programming", "Dr. Smith");

    myGradeBook.displayMessage();

   
    myGradeBook.setInstructorName("Prof. Johnson");

    std::cout << "\nAfter changing the instructor's name:\n";
    myGradeBook.displayMessage();

    return 0;
}
