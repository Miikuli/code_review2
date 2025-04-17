#include "stack.h"
#include <sstream>
using namespace std;

class TNode {
public:
    int data;
    TNode* next;

    TNode(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    TNode* top;

public:
    Stack() : top(nullptr) {}
    ~Stack() { clearStack(); }

    // Проверка на пустоту стека
    bool isEmpty() const { return top == nullptr; }

    // Добавление элемента в стек
    void push(int value) {
        TNode* newNode = new TNode(value);
        newNode->next = top;
        top = newNode;
    }

    // Удаление элемента из стека
    bool pop() {
        if (isEmpty()) return false;

        TNode* temp = top;
        top = top->next;
        delete temp;
        return true;
    }

    // Получение данных вершины стека
    bool peek(int& value) const {
        if (isEmpty()) return false;
        value = top->data;
        return true;
    }

    // Вывод содержимого стека
    string toString() const {
        if (isEmpty()) return "Стек пуст!";

        ostringstream oss;
        oss << "Элементы стека: ";

        TNode* current = top;
        while (current != nullptr) {
            oss << current->data << " ";
            current = current->next;
        }

        return oss.str();
    }

    // Очистка стека
    void clearStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Получение указателя на вершину стека
    TNode* getTop() const { return top; }

    friend void addElementAndPrintAddress(Stack& stack, int D);
};

void addElementAndPrintAddress(Stack& stack, int D) {
    stack.push(D);
    std::cout << "Адрес новой вершины стека: " << stack.getTop() << std::endl;
}
