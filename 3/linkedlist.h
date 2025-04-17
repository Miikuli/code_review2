/*
Все динамические структуры данных реализовывать через классы. Не использовать STL.  Для каждой динамической структуры должен быть предусмотрен
стандартный набор методов - добавления/удаления/вывода элементов. Во всех задачах обязательно
наличие дружественного интерфейса. Ввод данных с клавиатуры.


Дан текстовый файл, в первой строке которого хранится число N, а во второй
строке N целых чисел. Необходимо создать упорядоченный по убыванию список, в который
поместить все эти элементы, при этом очередной элемент вставлять в список так, чтобы не
нарушалась его упорядоченность.*/


#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class LinkedList {
private:
    class TNode {
    public:
        int data;
        TNode* next;

        TNode(int value) : data(value), next(nullptr) {}
    };

    TNode* head; // Указатель на начало списка

public:
    // Конструктор и деструктор
    LinkedList();
    ~LinkedList();

    // Вставка элемента с сохранением упорядоченности (по убыванию)
    void insertSorted(int value);

    // Вывод списка
    void print() const;

    // Чтение данных из файла
    void readFromFile(const string& filename);

    // Очистка списка
    void clear();

    // Дружественная функция для чтения из файла
    friend void readFromFile(LinkedList& list, const string& filename);
};

// Дружественная функция для чтения из файла
void readFromFile(LinkedList& list, const string& filename);

#endif // LINKEDLIST_H
