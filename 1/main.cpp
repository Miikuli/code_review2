#include "stack.h"
#include <iostream>

using namespace std;

int getValidInput(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            return value;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Неверный ввод. Пожалуйста, введите целое число.\n";
    }
}

void displayMenu() {
    cout << "\nМеню:\n"
        << "1. Добавить элемент в стек\n"
        << "2. Удалить элемент из стека\n"
        << "3. Вывести элементы стека\n"
        << "4. Очистить стек\n"
        << "5. Выйти\n";
}

int main() {
    Stack stack;

    while (true) {
        displayMenu();
        int choice = getValidInput("Введите ваш выбор: ");

        switch (choice) {
        case 1: {
            int value = getValidInput("Введите число для добавления в стек: ");
            addElementAndPrintAddress(stack, value);
            break;
        }
        case 2:
            if (!stack.pop()) {
                cout << "Стек пуст! Удаление невозможно.\n";
            }
            break;
        case 3:
            cout << stack.toString() << endl;
            break;
        case 4:
            stack.clearStack();
            cout << "Стек очищен.\n";
            break;
        case 5:
            cout << "Выход из программы.\n";
            return 0;
        default:
            cout << "Неверный выбор! Пожалуйста, попробуйте снова.\n";
        }
    }
}