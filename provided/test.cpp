#include "grade.hpp"
#include "gradebook.hpp"
#include <cassert>
#include <iostream>
#include <cmath>

using namespace std;

bool isClose(double v1, double v2) {
  double epsilon = 1e-4;
  return fabs(v1 - v2) < epsilon;
}

void testGrade() {
  cout << "Testing grade class" << endl;
  Grade grade;
  assert(grade.getName().empty());
  assert(isClose(grade.getGrade(), 0));
  Grade grade1("new name,90");
  assert(grade1.getName() == "new name");
  assert(isClose(grade1.getGrade(), 90));
  assert(grade1.infoLine() == "Name: new name | Grade: 90.0");
  assert(isClose(grade1.getGrade(), 90));
}

void testGradeBook() {
  cout << "Testing grade book class" << endl;
  GradeBook gradeBook("COP3014", 40, "gradebook.txt");
  assert(gradeBook.searchStudent("invalid student") == -1);
  assert(gradeBook.searchStudent("John Smith") == 0);
  assert(gradeBook.getCount() == 3);
  gradeBook.updateGrade(1, "Andrew Brown,60");
  assert(gradeBook.searchStudent("Andrew Brown") == 1);
  gradeBook.print();
  // test save
  gradeBook.save("test_output.txt");
  // load saved data
  GradeBook gradeBook1("COP3014", 40, "test_output.txt");
  assert(gradeBook.getCount() == 3);
  assert(gradeBook.searchStudent("Andrew Brown") == 1);
  cout << "You should see the last grade as 50\n";
}

int main() {
  testGrade();
  testGradeBook();

  cout << "All test passed!" << endl;

  return EXIT_SUCCESS;
}
