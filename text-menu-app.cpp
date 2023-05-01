#include "text-menu-app.hpp"
#include <iostream>
#include <string>

using namespace std;

void TextMenuApp::run() {
  int userResponse;
  string searchName;
  string gradeName;
  int searchIndex;
  string fileName;
  string newInfo;
  string userString;

  do {
    cout << "1. Print all grades\n2. Update a grade\n3. Save to file\n4. "
            "Exit\n";
    getline(cin >> ws, userString);
    if (isdigit(userString[0])) {
      userResponse = stoi(userString);
    } else {
      userResponse = -1;
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
      cout << "Please input the new information (format: student's name, "
              "comma, grade): ";
      getline(cin >> ws, newInfo);
      gradeBook.updateGrade(searchIndex, newInfo);
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
      cout << "\n";
      break;
    }
    cout << "\n";
  } while (userResponse != 4);
}
