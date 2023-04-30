#include "text-menu-app.hpp"
#include <iostream>
#include <string>

using namespace std;

void TextMenuApp::run() {
  int userResponse;
  bool validInput;
  string searchName;
  double grade;
  string gradeName;
  int searchIndex;
  string fileName;

  do {
    cout << "1. Print all grades\n2. Update a grade\n3. Save to file\n4. "
            "Exit\n";
    cin >> userResponse;
    validInput = ((userResponse <= 5) && (userResponse > 0)) ? true : false;

    while (!validInput) {
      cout << "Please enter a valid selection" << endl;
      cin >> userResponse;

      validInput = ((userResponse <= 5) && (userResponse > 0)) ? true : false;
    }

    switch (userResponse) {
    case 1:
      cout << "Printing all grades" << endl;
      gradeBook.print();
      break;

    case 2:
      cout << "Enter the name of the student whose grade you would like to "
              "update: "
           << endl;
      getline(cin >> ws, searchName);
      searchIndex = gradeBook.searchStudent(searchName);
      while (searchIndex == -1) {
        cout << "Student not found. Please enter a valid name: ";
        getline(cin >> ws, searchName);
        searchIndex = gradeBook.searchStudent(searchName);
      }
      cout << "Enter the new grade: ";
      cin >> grade;
      gradeBook.updateGrade(searchIndex, searchName);
      cout << searchName << " has been updated" << endl;
      break;

    case 3:
      cout << "Please enter a file name: " << endl;
      getline(cin >> ws, fileName);
      gradeBook.save(fileName);
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
