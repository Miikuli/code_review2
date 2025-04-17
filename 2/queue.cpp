/* Даны указатели P1 и P2 на начало и конец непустой очереди. Извлекать из очереди
элементы, пока значение начального элемента очереди не станет четным, и выводить значения
извлеченных элементов(если очередь не содержит элементов с четными значениями, то извлечь
все ее элементы).Вывести также новые адреса начала и конца очереди(для пустой очереди
дважды вывести nullptr).После извлечения элементов из очереди освобождать память, которую
они занимали.


Для каждой динамической структуры должен быть предусмотрен стандартный набор методов -
добавления/удаления/вывода элементов.
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.


В заданиях данной подгруппы структура «очередь» (queue) моделируется цепочкой связанных
узлов-записей типа TNode. Поле Next последнего элемента цепочки равно nullptr. Началом
очереди («головой», head) считается первый элемент цепочки, концом («хвостом», tail) — ее
последний элемент. Для возможности быстрого добавления в конец очереди нового элемента
удобно хранить, помимо указателя на начало очереди, также и указатель на ее конец. В случае
пустой очереди указатели на ее начало и конец полагаются равными nullptr. Как и для стека,
значением элемента очереди считается значение его поля Data.*/

#include "queue.h"
#include <sstream>

using namespace std;

class Queue {
private:
    struct TNode {
        int data;
        TNode* next;

        TNode(int value) : data(value), next(nullptr) {}
    };

    TNode* head;
    TNode* tail;

public:
    Queue() : head(nullptr), tail(nullptr) {}

    ~Queue() {
        clear();
    }

    void enqueue(int value) {
        TNode* newNode = new TNode(value);
        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        newNode->next = nullptr;
    }

    bool dequeue(int& value) {
        if (isEmpty()) return false;

        TNode* temp = head;
        value = head->data;
        head = head->next;

        if (head == nullptr) {
            tail = nullptr;
        }

        delete temp;
        return true;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    string toString() const {
        if (isEmpty()) return "Очередь пуста";

        std::ostringstream oss;
        TNode* current = head;
        while (current != nullptr) {
            oss << current->data << " ";
            current = current->next;
        }

        return oss.str();
    }

    TNode* getHead() const {
        return head;
    }

    bool getHeadData(int& value) const {
        if (isEmpty()) return false;
        value = head->data;
        return true;
    }

    bool getTailData(int& value) const {
        if (isEmpty()) return false;
        value = tail->data;
        return true;
    }

    TNode* getTail() const {
        return tail;
    }

    string extractUntilEven() {
        std::ostringstream oss;
        int value;

        while (!isEmpty() && (head->data % 2 != 0)) {
            dequeue(value);
            oss << value << " ";
        }

        return oss.str();
    }

    void clear() {
        int temp;
        while (dequeue(temp));
    }
};

bool isNumber(const std::string& str) {
    if (str.empty()) return false;
    size_t start = (str[0] == '-' || str[0] == '+') ? 1 : 0;

    if (start == str.size()) return false;

    for (size_t i = start; i < str.size(); ++i) {
        if (!isdigit(str[i])) return false;
    }

    return true;
}
