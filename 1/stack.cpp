/*Дано число D и указатель P1 на вершину непустого стека. 
Добавить элемент со значением D в стек и вывести адрес P2 новой вершины стека.

Для каждой динамической структуры должен быть предусмотрен стандартный набор методов - 
добавления/удаления/вывода элементов. 
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.

В заданиях подгруппы структура «стек» (stack) моделируется цепочкой связанных
узлов-записей типа TNode. Поле Next последнего элемента цепочки равно nullptr. Вершиной
стека (top) считается первый элемент цепочки. Для доступа к стеку используется указатель на
его вершину (для пустого стека данный указатель полагается равным nullptr). Значением
элемента стека считается значение его поля Data*/

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

    // Ïðîâåðêà íà ïóñòîòó ñòåêà
    bool isEmpty() const { return top == nullptr; }

    // Äîáàâëåíèå ýëåìåíòà â ñòåê
    void push(int value) {
        TNode* newNode = new TNode(value);
        newNode->next = top;
        top = newNode;
    }

    // Óäàëåíèå ýëåìåíòà èç ñòåêà
    bool pop() {
        if (isEmpty()) return false;

        TNode* temp = top;
        top = top->next;
        delete temp;
        return true;
    }

    // Ïîëó÷åíèå äàííûõ âåðøèíû ñòåêà
    bool peek(int& value) const {
        if (isEmpty()) return false;
        value = top->data;
        return true;
    }

    // Âûâîä ñîäåðæèìîãî ñòåêà
    string toString() const {
        if (isEmpty()) return "Ñòåê ïóñò!";

        ostringstream oss;
        oss << "Ýëåìåíòû ñòåêà: ";

        TNode* current = top;
        while (current != nullptr) {
            oss << current->data << " ";
            current = current->next;
        }

        return oss.str();
    }

    // Î÷èñòêà ñòåêà
    void clearStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Ïîëó÷åíèå óêàçàòåëÿ íà âåðøèíó ñòåêà
    TNode* getTop() const { return top; }

    friend void addElementAndPrintAddress(Stack& stack, int D);
};

void addElementAndPrintAddress(Stack& stack, int D) {
    stack.push(D);
    std::cout << "Àäðåñ íîâîé âåðøèíû ñòåêà: " << stack.getTop() << std::endl;
}
