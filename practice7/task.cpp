#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    double* grades;
    int gradeCount;
};

void addStudent(Student*& students, int& studentCount, const string& name, const double* grades, int gradeCount) {
    Student* newStudents = new Student[studentCount + 1];

    for (int i = 0; i < studentCount; ++i) {
        newStudents[i] = students[i];
    }

    newStudents[studentCount].name = name;
    newStudents[studentCount].gradeCount = gradeCount;
    newStudents[studentCount].grades = new double[gradeCount];

    for (int i = 0; i < gradeCount; ++i) {
        newStudents[studentCount].grades[i] = grades[i];
    }

    delete[] students;
    students = newStudents;
    studentCount++;
}

void removeStudent(Student*& students, int& studentCount, const string& name) {
    bool found = false;
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].name == name) {
            found = true;

            delete[] students[i].grades;

            for (int j = i; j < studentCount - 1; ++j) {
                students[j] = students[j + 1];
            }

            studentCount--;

            Student* newStudents = new Student[studentCount];
            for (int k = 0; k < studentCount; ++k) {
                newStudents[k] = students[k];
            }

            delete[] students;
            students = newStudents;

            cout << "Student " << name << " removed.\n";
            break;
        }
    }

    if (!found) {
        cout << "Student with this name not found.\n";
    }
}

double calculateAverageGrade(const Student& student) {
    double sum = 0;
    for (int i = 0; i < student.gradeCount; ++i) {
        sum += student.grades[i];
    }
    return sum / student.gradeCount;
}

void displayStudents(const Student* students, int studentCount) {
    if (studentCount == 0) {
        cout << "Student list is empty.\n";
        return;
    }

    for (int i = 0; i < studentCount; ++i) {
        cout << "Student: " << students[i].name << "\nGrades: ";
        for (int j = 0; j < students[i].gradeCount; ++j) {
            cout << students[i].grades[j] << " ";
        }
        cout << "\nAverage grade: " << calculateAverageGrade(students[i]) << "\n\n";
    }
}

int main() {
    Student* students = nullptr;
    int studentCount = 0;

    while (true) {
        int choice;
        cout << "\nMenu:\n";
        cout << "1. Add student\n";
        cout << "2. Remove student\n";
        cout << "3. Show all students\n";
        cout << "4. Exit\n";
        cout << "Choose an action: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            int gradeCount;
            cout << "Enter student's name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter the number of grades: ";
            cin >> gradeCount;

            double* grades = new double[gradeCount];
            cout << "Enter grades:\n";
            for (int i = 0; i < gradeCount; ++i) {
                cin >> grades[i];
            }

            addStudent(students, studentCount, name, grades, gradeCount);

            delete[] grades;

            break;
        }
        case 2: {
            string name;
            cout << "Enter the student's name to remove: ";
            cin.ignore();
            getline(cin, name);
            removeStudent(students, studentCount, name);
            break;
        }
        case 3:
            displayStudents(students, studentCount);
            break;
        case 4:
            for (int i = 0; i < studentCount; ++i) {
                delete[] students[i].grades;
            }
            delete[] students;
            cout << "Program terminated.\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
