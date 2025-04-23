#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>

using namespace std;

struct Subscriber {
  string surname;
  string phone;
};

struct Elem {
  Subscriber info;
  Elem* link;
};

void enqueue(Elem*& first, Elem*& last, const Subscriber& value);
bool dequeue(Elem*& first, Elem*& last, Subscriber& removed);
void printQueue(Elem* first);
void destroyQueue(Elem*& first, Elem*& last);
bool searchBySurname(Elem* first, const string& surname, Subscriber& result);
bool searchByPhone(Elem* first, const string& phone, Subscriber& result);

#endif //FUNCTIONS_H