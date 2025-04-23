#include <iostream>
#include <string>
#include "./functions/functions.h"

using namespace std;

int main() {
    Elem* first = nullptr;
    Elem* last = nullptr;

    // Заповнення черги
    enqueue(first, last, { "Іваненко", "0971234567" });
    enqueue(first, last, { "Петренко", "0507654321" });
    enqueue(first, last, { "Сидоренко", "0639876543" });

    cout << "\n Телефонний довідник:\n";
    printQueue(first);

    //  Пошук за прізвищем
    string searchName;
    cout << "Введіть прізвище для пошуку: ";
    getline(cin, searchName);
    Subscriber found;
    if (searchBySurname(first, searchName, found)) {
        cout << "Знайдено: " << found.surname << ", Телефон: " << found.phone << endl;
    } else {
        cout << "Абонента з прізвищем \"" << searchName << "\" не знайдено.\n";
    }

    //  Пошук за номером
    string searchPhone;
    cout << "\nВведіть номер телефону для пошуку: ";
    getline(cin, searchPhone);
    if (searchByPhone(first, searchPhone, found)) {
        cout << "Знайдено: " << found.surname << ", Телефон: " << found.phone << endl;
    } else {
        cout << "Абонента з номером \"" << searchPhone << "\" не знайдено.\n";
    }

    //  Очищення пам’яті
    destroyQueue(first, last);
    return 0;
}
