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

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>

class Queue {
private:
    struct TNode {
        int data;
        TNode* next;

        TNode(int val) : data(val), next(nullptr) {}
    };

    TNode* head;  // Указатель на начало очереди (P1)
    TNode* tail;  // Указатель на конец очереди (P2)

public:
    // Конструктор и деструктор
    Queue();
    ~Queue();

    // Добавление элемента в очередь
    void enqueue(int value);

    // Извлечение элемента из очереди
    bool dequeue(int& value);

    // Проверка на пустоту
    bool isEmpty() const;

    // Вывод элементов очереди
    std::string toString() const;

    // Получение данных первого элемента
    bool getHeadData(int& value) const;

    // Получение данных последнего элемента
    bool getTailData(int& value) const;

    // Получение указателей
    TNode* getHead() const;
    TNode* getTail() const;

    // Извлечение элементов до первого четного
    std::string extractUntilEven();

    // Очистка очереди
    void clear();
};

// Вспомогательная функция для проверки числа
bool isNumber(const std::string& str);

#endif // QUEUE_H
