#include "gradebook.hpp"
#include <string>
#include <iostream>

GradeBook::GradeBook()
{
  courseName = "NOT_SET";
  grades = new Grade[40];
  count = 0;
}

GradeBook::GradeBook(const std::string &courseName, int size)
{
  this->courseName = courseName;
  grades = new Grade[40];
  count = 0;
}

GradeBook::~GradeBook()
{
  std::cout << "Deleting grades..." << std::endl;
  delete[] grades;
  std::cout << "Done." << std::endl;
}

// getter of the count of students
int GradeBook::getCount() const
{
  return count;
}

// getter of the course name
std::string GradeBook::getName() const
{
  return courseName;
}

// add a new grade
// do not worry about the size limit
void GradeBook::addGrade(const std::string &name, double grade)
{
  grades[count] = Grade(name, grade);
  count++;
}

// search the grade by student's name
// return -1 if not found
int GradeBook::searchStudent(const std::string &name) const
{
  for (int i = 0; i < count; i++)
  {
    if (grades[i].getName() == name)
    {
      return i;
    }
  }
  return -1;
}

// print the student's info providing a valid index
// assuming that the index is valid (get from the search)
// ask the Grade object to print
void GradeBook::printStudent(int studentIndex) const
{
  this->grades[studentIndex].print();
}

// print a summary of the course like:
// GradeBook of course COP 3014
// Name: John Smith | Grade: 90.0
// Name: Laura Johnson | Grade: 83.0
// Name: Josh Brown | Grade: 77.0

// ask each Grade object to print itself
void GradeBook::print() const
{
  std::cout << "GradeBook of course " << getName() << "\n";
  for (int i = 0; i < count; i++)
  {
    grades[i].print();
  }
}

void GradeBook::removeStudent(const int index)
{
  for (int i = index; i < count; i++)
  {
    grades[i] = grades[i + 1];
  }
  count--;
  Grade *temp = new Grade[count];
  for (int i = 0; i < count; i++)
  {
    temp[i] = grades[i];
  }
  delete[] grades;
  grades = new Grade[count];
  for (int i = 0; i < count; i++)
  {
    grades[i] = temp[i];
  }
  delete[] temp;
}

void GradeBook::updateGrade(const int index, double grade)
{
  grades[index].setGrade(grade);
}