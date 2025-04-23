#include "functions.h"
#include <iostream>
#include <fstream>
#include <string>

void enqueue(Elem*& first, Elem*& last, const Subscriber& value) {
  Elem* tmp = new Elem{ value, nullptr };
  if (last)
    last->link = tmp;
  last = tmp;
  if (!first)
    first = tmp;
}

bool dequeue(Elem*& first, Elem*& last, Subscriber& removed) {
  if (!first)
    return false;
  Elem* tmp = first;
  removed = tmp->info;
  first = first->link;
  if (!first)
    last = nullptr;
  delete tmp;
  return true;
}

void printQueue(Elem* first) {
  if (!first) {
    cout << "Телефонний довідник порожній.\n";
    return;
  }

  cout << left << setw(20) << "Прізвище" << setw(15) << "Телефон" << endl;
  cout << string(35, '-') << endl;
  for (Elem* cur = first; cur; cur = cur->link) {
    cout << left << setw(20) << cur->info.surname
         << setw(15) << cur->info.phone << endl;
  }
  cout << endl;
}

void destroyQueue(Elem*& first, Elem*& last) {
  Subscriber tmp;
  while (dequeue(first, last, tmp)) {
    // Просто видаляємо
  }
}

bool searchBySurname(Elem* first, const string& surname, Subscriber& result) {
  while (first) {
    if (first->info.surname == surname) {
      result = first->info;
      return true;
    }
    first = first->link;
  }
  return false;
}

bool searchByPhone(Elem* first, const string& phone, Subscriber& result) {
  while (first) {
    if (first->info.phone == phone) {
      result = first->info;
      return true;
    }
    first = first->link;
  }
  return false;
}
