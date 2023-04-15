#include "text-menu-app.hpp"
#include <iostream>
#include <string>

using namespace std;

void TextMenuApp::run()
{
  int userResponse;
  bool validInput;
  string searchName;
  double grade;
  string gradeName;
  int searchIndex;

  do
  {
    cout << "1. Print all grades\n2. Remove a grade\n3. Update a grade\n4. Exit\n";
    cin >> userResponse;
    validInput = ((userResponse <= 5) && (userResponse > 0)) ? true : false;

    while (!validInput)
    {
      cout << "Please enter a valid selection" << endl;
      cin >> userResponse;

      validInput = ((userResponse <= 5) && (userResponse > 0)) ? true : false;
    }
    switch (userResponse)
    {
    case 1:
      cout << "Printing all grades" << endl;
      gradeBook.print();
      break;
    case 2:
      cout << "Removing a grade..." << endl;
      cout << "Enter the name of the student:" << endl;
      getline(cin >> ws, searchName);
      searchIndex = gradeBook.searchStudent(searchName);
      while (searchIndex == -1)
      {
        cout << "Name not found! Please input an existing name" << endl;
        getline(cin >> ws, searchName);
        searchIndex = gradeBook.searchStudent(searchName);
      }
      gradeBook.removeStudent(searchIndex);
      break;
    case 3:
      cout << "Adding a new grade..." << endl;
      cout << "Enter the name of the student: " << endl;
      getline(cin >> ws, gradeName);
      cout << "Enter the grade: " << endl;
      cin >> grade;
      while (grade < 0 || grade > 100)
      {
        cout << "Please enter a valid grade" << endl;
        cin >> grade;
      }
      gradeBook.addGrade(gradeName, grade);
      break;
    case 4:
      cout << "Exiting" << endl;
      break;
    default:
      cout << "Please enter a valid selection" << endl;
      break;
    }
    cout << "\n";
  } while (userResponse != 4);
}
