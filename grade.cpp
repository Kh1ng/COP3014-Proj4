#include "grade.hpp"
#include <fstream>
#include <iomanip>
#include <sstream>

Grade::Grade() {}

Grade::Grade(const std::string &infoLine) {
  std::istringstream iss(infoLine);
  getline(iss, studentName, ',');
  iss >> grade;
};

std::string Grade::getName() const { return studentName; }

double Grade::getGrade() const { return grade; }

std::string Grade::infoLine() const {
  //"Name: new name | Grade: 90.0"
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(1);
  oss << "Name: " << studentName << " | Grade: " << getGrade();
  return oss.str();
}

void Grade::setGrade(double newGrade) { grade = newGrade; }

void Grade::setName(const std::string &newName) { studentName = newName; }
