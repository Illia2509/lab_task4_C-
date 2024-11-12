#include <iostream>     // Для введення та виведення
#include <vector>       // Для використання динамічного масиву (вектора)
#include <algorithm>    // Для використання функції сортування
#include <iomanip>      // Для форматування виводу

// Структура для зберігання інформації про студента
struct Student {
    std::string name;      // Ім'я студента
    std::string faculty;   // Факультет студента
    std::string group;     // Група студента
    int absences;          // Кількість пропусків

    // Конструктор для ініціалізації студента
    Student(std::string n, std::string f, std::string g, int a)
        : name(n), faculty(f), group(g), absences(a) {}
};

// Функція для порівняння студентів за кількістю пропусків у спадному порядку
bool compareAbsences(const Student &a, const Student &b) {
    return a.absences > b.absences;  // Повертає true, якщо a має більше пропусків, ніж b
}

int main() {
    std::vector<Student> students;  // Вектор для зберігання інформації про студентів
    int numStudents;  // Кількість студентів

    // Отримуємо кількість студентів, принаймні 10
    do {
        std::cout << "Введіть кількість студентів (мінімум 10): ";
        std::cin >> numStudents;

        // Перевірка, що введено принаймні 10 студентів
        if (numStudents < 10) {
            std::cout << "Помилка: потрібно ввести принаймні 10 студентів.\n";
        }
    } while (numStudents < 10);

    // Отримуємо інформацію про кожного студента
    for (int i = 0; i < numStudents; ++i) {
        std::string name, faculty, group;  // Змінні для збереження даних студента
        int absences;                      // Змінна для збереження кількості пропусків

        std::cout << "Студент #" << (i + 1) << ":\n";
        std::cout << "Введіть ПІБ: ";
        std::cin.ignore();                 // Очистка буфера перед зчитуванням рядка
        std::getline(std::cin, name);      // Зчитуємо ПІБ
        std::cout << "Введіть факультет: ";
        std::getline(std::cin, faculty);   // Зчитуємо факультет
        std::cout << "Введіть групу: ";
        std::getline(std::cin, group);     // Зчитуємо групу
        std::cout << "Введіть кількість пропусків: ";
        std::cin >> absences;              // Зчитуємо кількість пропусків

        // Додаємо створеного студента до вектора
        students.emplace_back(name, faculty, group, absences);
    }

    // Сортуємо вектор студентів за кількістю пропусків у спадному порядку
    std::sort(students.begin(), students.end(), compareAbsences);

    // Виводимо топ-10 студентів з найбільшою кількістю пропусків
    std::cout << "\nТоп-10 студентів з найбільшою кількістю пропусків:\n";
    for (int i = 0; i < 10 && i < students.size(); ++i) {
        std::cout << students[i].name << " (Факультет: " << students[i].faculty 
                  << ", Група: " << students[i].group 
                  << ", Пропуски: " << students[i].absences << ")\n";
    }

    return 0;  // Завершуємо програму
}
