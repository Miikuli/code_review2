/* Элементами контейнеров являются целые числа. Для
заполнения контейнера использовать итератор и конструктор соответствующего контейнера,
для вывода элементов использовать итератор (для вывода элементов в обратном порядке
использовать обратные итераторы, возвращаемые функциями-членами rbegin и rend)
Обязательно наличие дружественного интерфейса. Ввод данных организовать
разными способами (с клавиатуры, рандом, из файла)


 Дан дек D с нечетным количеством элементов N (≥ 5). Добавить в начало дека пять
его средних элементов в исходном порядке. Использовать один вызов функции-члена insert. */

#ifndef DEQUE_OPERATIONS_H
#define DEQUE_OPERATIONS_H

#include <deque>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <iterator>

using namespace std;

// Вставка средних элементов в начало дека
void insertMiddleElements(deque<int>& d);

// Создание дека с клавиатуры
deque<int> createDequeFromKeyboard();

// Создание дека со случайными числами
deque<int> createRandomDeque(int count);

// Создание дека из файла
deque<int> createDequeFromFile(const string& filename = "input.txt");

// Вывод дека с использованием итераторов
void printDequeWithIterators(const deque<int>& d);

#endif // DEQUE_OPERATIONS_H
