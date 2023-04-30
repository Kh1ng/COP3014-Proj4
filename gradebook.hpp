#ifndef GRADEBOOK_HPP
#define GRADEBOOK_HPP

#include "grade.hpp"
#include <string>

class GradeBook {
private:
  std::string courseName;
  std::string path;
  Grade *grades;
  int capacity;
  int count;

public:
  GradeBook();

  GradeBook(const std::string &courseName, int capacity,
            const std::string &path);

  ~GradeBook();

  int getCount() const;

  int searchStudent(const std::string &name) const;

  void loadFile();

  void updateGrade(int index, const std::string &name);

  void save(const std::string &path) const;

  void print() const;
};

#endif // GRADEBOOK_HPP
