#include "grade.hpp"
#include "gradebook.hpp"
#include "text-menu-app.hpp"

int main() {

  // create initial data of a sample gradebook
  GradeBook gradeBook("COP 3014", 40, "gradebook.txt");

  // create and run the text menu based app
  TextMenuApp menu(gradeBook);
  menu.run();

  return EXIT_SUCCESS;
}
