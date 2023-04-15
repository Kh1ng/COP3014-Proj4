#include "grade.hpp"
#include <iostream>

    Grade::Grade() {

    }
  // parameterized constructor to set the initial values of
  //   all instance variables
  Grade::Grade(std::string const &name, double grade) {
    this -> studentName = name;
    this -> grade = grade;
  };
  // getter of the student's name
  std::string Grade::getName() const {
    return studentName;
  }
  // getter of the grade
  double Grade::getGrade() const { 
    return grade;
  }

  void Grade::setGrade(double grade) {
    this -> grade = grade;
  }

  // print the grade info in the format like:
  //   Name: Jerry Williams | Grade: 78.0
  // should display one decimal place
  void Grade::print() const {
    std::cout << "Name : " << getName() << " | Grade: " << getGrade() << std::endl;
  }
