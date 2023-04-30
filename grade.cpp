#include "grade.hpp"
#include <fstream>
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
  std::ostringstream oss;
  oss << studentName << "," << grade;
  return oss.str();
}
