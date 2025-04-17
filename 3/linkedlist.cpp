/*
Все динамические структуры данных реализовывать через классы. Не использовать STL.  Для каждой динамической структуры должен быть предусмотрен
стандартный набор методов - добавления/удаления/вывода элементов. Во всех задачах обязательно
наличие дружественного интерфейса. Ввод данных с клавиатуры.


Дан текстовый файл, в первой строке которого хранится число N, а во второй
строке N целых чисел. Необходимо создать упорядоченный по убыванию список, в который
поместить все эти элементы, при этом очередной элемент вставлять в список так, чтобы не
нарушалась его упорядоченность.*/

#include "linkedlist.h"

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::insertSorted(int value) {
    TNode* newNode = new TNode(value);

    // Вставка в начало, если список пуст или новый элемент больше головного
    if (head == nullptr || value > head->data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Поиск места для вставки
    TNode* current = head;
    while (current->next != nullptr && current->next->data > value) {
        current = current->next;
    }

    // Вставка нового узла
    newNode->next = current->next;
    current->next = newNode;
}

void LinkedList::print() const {
    TNode* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void LinkedList::readFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла: " << filename << endl;
        return;
    }

    int N;
    file >> N; // Чтение количества элементов

    int value;
    for (int i = 0; i < N; ++i) {
        if (!(file >> value)) {
            cerr << "Ошибка чтения данных из файла" << endl;
            break;
        }
        insertSorted(value);
    }

    file.close();
}

void LinkedList::clear() {
    while (head != nullptr) {
        TNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void readFromFile(LinkedList& list, const string& filename) {
    list.readFromFile(filename);
}
