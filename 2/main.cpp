#include "queue.h"
#include <iostream>
#include <string>

using namespace std;

int getValidNumber(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        cin >> input;

        if (isNumber(input)) {
            return stoi(input);
        }

        cout << "Ошибка: введите целое число!\n";
        cin.clear();
    }
}

int main() {
    Queue queue;

    // Ввод количества элементов
    int count = getValidNumber("Введите количество элементов в очереди: ");

    // Ввод элементов очереди
    for (int i = 0; i < count; ++i) {
        int num = getValidNumber("Введите элемент " + to_string(i + 1) + ": ");
        queue.enqueue(num);
    }

    // Вывод исходной очереди
    cout << "\nИзначальная очередь: " << queue.toString() << endl;

    // Извлечение элементов до первого четного
    string extracted = queue.extractUntilEven();
    cout << "Извлеченные элементы: " << (extracted.empty() ? "нет" : extracted) << endl;

    // Вывод измененной очереди
    cout << "Измененная очередь: " << queue.toString() << endl;

    // Вывод информации о первом элементе
    int headValue;
    if (queue.getHeadData(headValue)) {
        cout << "Значение первого элемента: " << headValue << endl;
    }
    else {
        cout << "Очередь пуста, первого элемента нет" << endl;
    }

    // Вывод адреса начала очереди
    cout << "Адрес начала очереди (P1): " << queue.getHead() << endl;

    // Вывод информации о последнем элементе
    int tailValue;
    if (queue.getTailData(tailValue)) {
        cout << "Значение последнего элемента: " << tailValue << endl;
    }
    else {
        cout << "Очередь пуста, последнего элемента нет" << endl;
    }

    // Вывод адреса конца очереди
    cout << "Адрес конца очереди (P2): " << queue.getTail() << endl;

    return 0;
}
