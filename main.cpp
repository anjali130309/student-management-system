#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Student {
public:
    int id;
    string name;
    int age;
    string course;
};

vector<Student> students;

// Function Declarations
void menu();
void addStudent();
void viewStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
void saveToFile();
void loadFromFile();


// MENU
void menu() {
    cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
    cout << "1. Add Student\n";
    cout << "2. View Students\n";
    cout << "3. Search Student\n";
    cout << "4. Update Student\n";
    cout << "5. Delete Student\n";
    cout << "6. Exit\n";
}


// ADD STUDENT
void addStudent() {

    Student s;

    cout << "\nEnter Student ID: ";
    cin >> s.id;

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, s.name);

    cout << "Enter Age: ";
    cin >> s.age;

    cin.ignore();

    cout << "Enter Course: ";
    getline(cin, s.course);

    students.push_back(s);

    saveToFile();

    cout << "\nStudent Added Successfully!\n";
}


// VIEW STUDENTS
void viewStudents() {

    if (students.empty()) {
        cout << "\nNo Student Records Found!\n";
        return;
    }

    cout << "\n===== STUDENT RECORDS =====\n";

    for (auto s : students) {

        cout << "\nID     : " << s.id;
        cout << "\nName   : " << s.name;
        cout << "\nAge    : " << s.age;
        cout << "\nCourse : " << s.course << endl;
    }
}


// SEARCH STUDENT
void searchStudent() {

    int id;

    cout << "\nEnter Student ID to Search: ";
    cin >> id;

    for (auto s : students) {

        if (s.id == id) {

            cout << "\nStudent Found!\n";

            cout << "\nID     : " << s.id;
            cout << "\nName   : " << s.name;
            cout << "\nAge    : " << s.age;
            cout << "\nCourse : " << s.course << endl;

            return;
        }
    }

    cout << "\nStudent Not Found!\n";
}


// UPDATE STUDENT
void updateStudent() {

    int id;

    cout << "\nEnter Student ID to Update: ";
    cin >> id;

    for (auto &s : students) {

        if (s.id == id) {

            cin.ignore();

            cout << "Enter New Name: ";
            getline(cin, s.name);

            cout << "Enter New Age: ";
            cin >> s.age;

            cin.ignore();

            cout << "Enter New Course: ";
            getline(cin, s.course);

            cout << "\nStudent Updated Successfully!\n";

            return;
        }
    }

    cout << "\nStudent Not Found!\n";
}


// DELETE STUDENT
void deleteStudent() {

    int id;

    cout << "\nEnter Student ID to Delete: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++) {

        if (students[i].id == id) {

            students.erase(students.begin() + i);

            cout << "\nStudent Deleted Successfully!\n";

            return;
        }
    }

    cout << "\nStudent Not Found!\n";
}



// SAVE DATA TO FILE
void saveToFile() {

    ofstream file("students.txt");

    for (auto s : students) {

        file << s.id << ","
             << s.name << ","
             << s.age << ","
             << s.course << endl;
    }

    file.close();
}


// LOAD DATA FROM FILE
void loadFromFile() {

    ifstream file("students.txt");

    string line;

    while (getline(file, line)) {

        stringstream ss(line);

        Student s;

        string id, age;

        getline(ss, id, ',');
        getline(ss, s.name, ',');
        getline(ss, age, ',');
        getline(ss, s.course, ',');

        s.id = stoi(id);
        s.age = stoi(age);

        students.push_back(s);
    }

    file.close();
}
// MAIN FUNCTION
int main() {

    loadFromFile();

    int choice;

    do {

        menu();

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                addStudent();
                break;

            case 2:
                viewStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                saveToFile();
                cout << "\nData Saved Successfully!";
                cout << "\nExiting Program...\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 6);

    return 0;
}