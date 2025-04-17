/* Дан двусвязный линейный список и указатель первый элемент этого
списка. Все элементы списка хранят различные между собой значения. Необходимо
вывести значения элементов списка, которые находятся между наименьшим и
наибольшим элементами списка, в том порядке, в каком они находятся в исходном
списке. Использовать процедуры.

Все динамические структуры данных реализовывать через классы. Не использовать STL.
Для каждой динамической структуры должен быть предусмотрен
стандартный набор методов - добавления/удаления/вывода элементов.
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.*/

#ifndef DLLIST_H
#define DLLIST_H

#include <iostream>

using namespace std;

class DoublyLinkedList {
private:
    struct TNode {
        int value;
        TNode* prev;
        TNode* next;

        TNode(int val) : value(val), prev(nullptr), next(nullptr) {}
    };

    TNode* head; // Указатель на первый элемент

public:
    // Конструктор и деструктор
    DoublyLinkedList();
    ~DoublyLinkedList();

    // Основные методы
    void addElement(int value);
    void printList() const;
    void printBetweenMinMax() const;
    void clear();

private:
    // Вспомогательные методы
    void findMinMax(TNode*& min, TNode*& max) const;
    bool isFirst(TNode* first, TNode* second) const;
};

#endif // DLLIST_H
