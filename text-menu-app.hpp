#ifndef TEXT_MENU_APP_HPP
#define TEXT_MENU_APP_HPP

#include "gradebook.hpp"
#include <string>

class TextMenuApp {
  GradeBook &gradeBook;
 public:

  // Provided constructor
  //   initialize the gradeBook instance variable
  explicit TextMenuApp(GradeBook &gradeBook) : gradeBook(gradeBook) {};

  // drives the main logic of the text menu app
  void run();
};

#endif  // TEXT_MENU_APP_HPP
