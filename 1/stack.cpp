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

    // �������� �� ������� �����
    bool isEmpty() const { return top == nullptr; }

    // ���������� �������� � ����
    void push(int value) {
        TNode* newNode = new TNode(value);
        newNode->next = top;
        top = newNode;
    }

    // �������� �������� �� �����
    bool pop() {
        if (isEmpty()) return false;

        TNode* temp = top;
        top = top->next;
        delete temp;
        return true;
    }

    // ��������� ������ ������� �����
    bool peek(int& value) const {
        if (isEmpty()) return false;
        value = top->data;
        return true;
    }

    // ����� ����������� �����
    string toString() const {
        if (isEmpty()) return "���� ����!";

        ostringstream oss;
        oss << "�������� �����: ";

        TNode* current = top;
        while (current != nullptr) {
            oss << current->data << " ";
            current = current->next;
        }

        return oss.str();
    }

    // ������� �����
    void clearStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // ��������� ��������� �� ������� �����
    TNode* getTop() const { return top; }

    friend void addElementAndPrintAddress(Stack& stack, int D);
};

void addElementAndPrintAddress(Stack& stack, int D) {
    stack.push(D);
    std::cout << "����� ����� ������� �����: " << stack.getTop() << std::endl;
}
