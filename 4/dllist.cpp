/* Дан двусвязный линейный список и указатель первый элемент этого
списка. Все элементы списка хранят различные между собой значения. Необходимо
вывести значения элементов списка, которые находятся между наименьшим и
наибольшим элементами списка, в том порядке, в каком они находятся в исходном
списке. Использовать процедуры.

Все динамические структуры данных реализовывать через классы. Не использовать STL.
Для каждой динамической структуры должен быть предусмотрен
стандартный набор методов - добавления/удаления/вывода элементов.
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.*/

#include "dllist.h"

DoublyLinkedList::DoublyLinkedList() : head(nullptr) {}

DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

void DoublyLinkedList::addElement(int value) {
    TNode* newNode = new TNode(value);

    if (head == nullptr) {
        head = newNode;
    }
    else {
        TNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void DoublyLinkedList::printList() const {
    TNode* current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

void DoublyLinkedList::findMinMax(TNode*& min, TNode*& max) const {
    if (head == nullptr) return;

    min = max = head;
    TNode* current = head->next;

    while (current != nullptr) {
        if (current->value < min->value) min = current;
        if (current->value > max->value) max = current;
        current = current->next;
    }
}

bool DoublyLinkedList::isFirst(TNode* first, TNode* second) const {
    TNode* current = head;
    while (current != nullptr) {
        if (current == first) return true;
        if (current == second) return false;
        current = current->next;
    }
    return false;
}

void DoublyLinkedList::printBetweenMinMax() const {
    TNode* min = nullptr;
    TNode* max = nullptr;
    findMinMax(min, max);

    if (min == nullptr || max == nullptr || min == max) {
        cout << "Нет элементов для вывода!" << endl;
        return;
    }

    bool minFirst = isFirst(min, max);
    TNode* start = minFirst ? min : max;
    TNode* end = minFirst ? max : min;

    cout << "Элементы между " << min->value << " и " << max->value << ": ";
    TNode* current = start->next;
    bool hasElements = false;

    while (current != nullptr && current != end) {
        cout << current->value << " ";
        hasElements = true;
        current = current->next;
    }

    if (!hasElements) cout << "Отсутствуют";
    cout << endl;
}

void DoublyLinkedList::clear() {
    TNode* current = head;
    while (current != nullptr) {
        TNode* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}
