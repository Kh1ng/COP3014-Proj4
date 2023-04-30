#include "gradebook.hpp"
#include "grade.hpp"
#include <fstream>
#include <iostream>
#include <string>

GradeBook::GradeBook() {
  courseName = "Unnamed";
  grades = new Grade[40];
  this->count = 0;
  path = "gradebook.txt";
  capacity = 40;
  if (path != "") {
    loadFile();
  }
}

GradeBook::GradeBook(const std::string &courseName, int capacity,
                     const std::string &path) {
  this->courseName = "Unnamed";
  grades = new Grade[40];
  count = 0;
  this->path = path;
  capacity = 40;
  loadFile();
}

GradeBook::~GradeBook() {
  std::cout << "Deleting grades..." << std::endl;
  delete[] grades;
  std::cout << "Done." << std::endl;
}

int GradeBook::getCount() const { return count; }

int GradeBook::searchStudent(const std::string &name) const {
  int returnMe = -1;
  for (int i = 0; i < count; i++) {
    if (grades[i].getName() == name) {
      returnMe = i;
    }
  }
  return returnMe;
}

void GradeBook::loadFile() {
  std::ifstream file(path);
  if (file.is_open()) {
    std::string line;
    while (getline(file, line)) {
      if (count == capacity) {
        std::cerr << "Error: capacity exceeded." << std::endl;
        break;
      }
      grades[count++] = Grade(line);
    }
    file.close();
  } else {
    std::cerr << "Error: could not open file " << path << std::endl;
  }
}

void GradeBook::updateGrade(int index, const std::string &name) {}

void GradeBook::save(const std::string &path) const {
  std::ofstream outfile(path);
  if (outfile) {
    for (int i = 0; i < getCount(); ++i) {
      outfile << grades[i].infoLine() << std::endl;
    }
    outfile.close();
    std::cout << "File saved successfully!" << std::endl;
  } else {
    std::cout << "Error: Unable to open file " << path << std::endl;
  }
}

void GradeBook::print() const {
  std::cout << "Course name: " << courseName << std::endl;
  for (int i = 0; i < count; i++) {
    std::cout << grades[i].infoLine() << std::endl;
  }
}
