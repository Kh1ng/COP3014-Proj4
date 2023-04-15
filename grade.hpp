#ifndef GRADE_HPP
#define GRADE_HPP

#include <string>

class Grade {
  std::string studentName;
  double grade;
 public:
  // default constructor
  Grade();
  // parameterized constructor to set the initial values of
  //   all instance variables
  Grade(const std::string &name, double grade);
  // getter of the student's name
  std::string getName() const;
  // getter of the grade
  double getGrade() const;
  // print the grade info in the format like:
  //   Name: Jerry Williams | Grade: 78.0
  // should display one decimal place

  void setGrade(double grade);

  void print() const;
};

#endif // GRADE_HPP
