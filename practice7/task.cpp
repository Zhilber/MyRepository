#include <iostream>
#include <string>
using namespace std;

// Структура для збереження даних студента
struct Student {
    string name;    // Ім'я студента
    double* grades; // Оцінки студента (динамічний масив)
    int gradeCount; // Кількість оцінок
};

// Функція для додавання студента
void addStudent(Student*& students, int& studentCount, const string& name, const double* grades, int gradeCount) {
    // Збільшуємо кількість студентів
    Student* newStudents = new Student[studentCount + 1];

    // Копіюємо існуючих студентів до нового масиву
    for (int i = 0; i < studentCount; ++i) {
        newStudents[i] = students[i];
    }

    // Додаємо нового студента
    newStudents[studentCount].name = name;
    newStudents[studentCount].gradeCount = gradeCount;
    newStudents[studentCount].grades = new double[gradeCount];

    // Копіюємо оцінки студента
    for (int i = 0; i < gradeCount; ++i) {
        newStudents[studentCount].grades[i] = grades[i];
    }

    // Видаляємо старий масив і присвоюємо новий
    delete[] students;
    students = newStudents;
    studentCount++;
}

// Функція для видалення студента за ім'ям
void removeStudent(Student*& students, int& studentCount, const string& name) {
    bool found = false;
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].name == name) {
            found = true;

            // Видаляємо студента з масиву
            delete[] students[i].grades;

            // Переміщаємо всіх студентів після видаленого на одну позицію вліво
            for (int j = i; j < studentCount - 1; ++j) {
                students[j] = students[j + 1];
            }

            // Зменшуємо кількість студентів
            studentCount--;

            // Виділяємо новий масив
            Student* newStudents = new Student[studentCount];
            for (int k = 0; k < studentCount; ++k) {
                newStudents[k] = students[k];
            }

            // Видаляємо старий масив студентів і присвоюємо новий
            delete[] students;
            students = newStudents;

            cout << "Студента " << name << " видалено.\n";
            break;
        }
    }

    if (!found) {
        cout << "Студента з таким ім'ям не знайдено.\n";
    }
}

// Функція для обчислення середнього балу студента
double calculateAverageGrade(const Student& student) {
    double sum = 0;
    for (int i = 0; i < student.gradeCount; ++i) {
        sum += student.grades[i];
    }
    return sum / student.gradeCount;
}

// Функція для виведення всіх студентів та їхніх оцінок
void displayStudents(const Student* students, int studentCount) {
    if (studentCount == 0) {
        cout << "Список студентів порожній.\n";
        return;
    }

    for (int i = 0; i < studentCount; ++i) {
        cout << "Студент: " << students[i].name << "\nОцінки: ";
        for (int j = 0; j < students[i].gradeCount; ++j) {
            cout << students[i].grades[j] << " ";
        }
        cout << "\nСередній бал: " << calculateAverageGrade(students[i]) << "\n\n";
    }
}

int main() {
    Student* students = nullptr;  // Динамічний масив студентів
    int studentCount = 0;         // Кількість студентів

    while (true) {
        int choice;
        cout << "\nМеню:\n";
        cout << "1. Додати студента\n";
        cout << "2. Видалити студента\n";
        cout << "3. Показати всіх студентів\n";
        cout << "4. Вийти\n";
        cout << "Виберіть дію: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            int gradeCount;
            cout << "Введіть ім'я студента: ";
            cin.ignore();
            getline(cin, name);
            cout << "Введіть кількість оцінок: ";
            cin >> gradeCount;

            double* grades = new double[gradeCount];
            cout << "Введіть оцінки:\n";
            for (int i = 0; i < gradeCount; ++i) {
                cin >> grades[i];
            }

            addStudent(students, studentCount, name, grades, gradeCount);

            // Звільняємо динамічну пам'ять для оцінок після додавання студента
            delete[] grades;

            break;
        }
        case 2: {
            string name;
            cout << "Введіть ім'я студента для видалення: ";
            cin.ignore();
            getline(cin, name);
            removeStudent(students, studentCount, name);
            break;
        }
        case 3:
            displayStudents(students, studentCount);
            break;
        case 4:
            // Звільняємо пам'ять перед завершенням програми
            for (int i = 0; i < studentCount; ++i) {
                delete[] students[i].grades;
            }
            delete[] students;
            cout << "Завершення програми.\n";
            return 0;
        default:
            cout << "Невірний вибір! Спробуйте ще раз.\n";
        }
    }

    return 0;
}
