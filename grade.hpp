#ifndef GRADE_HPP
#define GRADE_HPP

#include <string>

class Grade {
private:
  std::string studentName;
  double grade;

public:
  Grade();

  Grade(const std::string &infoLine);

  std::string getName() const;

  double getGrade() const;

  std::string infoLine() const;

  void setGrade(const double newGrade);

  void setName(const std::string &newName);
};

#endif // GRADE_HPP
