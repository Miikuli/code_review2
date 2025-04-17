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
        cout << "Íåâåðíûé ââîä. Ïîæàëóéñòà, ââåäèòå öåëîå ÷èñëî.\n";
    }
}

void displayMenu() {
    cout << "\nÌåíþ:\n"
        << "1. Äîáàâèòü ýëåìåíò â ñòåê\n"
        << "2. Óäàëèòü ýëåìåíò èç ñòåêà\n"
        << "3. Âûâåñòè ýëåìåíòû ñòåêà\n"
        << "4. Î÷èñòèòü ñòåê\n"
        << "5. Âûéòè\n";
}

int main() {
    Stack stack;

    while (true) {
        displayMenu();
        int choice = getValidInput("Ââåäèòå âàø âûáîð: ");

        switch (choice) {
        case 1: {
            int value = getValidInput("Ââåäèòå ÷èñëî äëÿ äîáàâëåíèÿ â ñòåê: ");
            addElementAndPrintAddress(stack, value);
            break;
        }
        case 2:
            if (!stack.pop()) {
                cout << "Ñòåê ïóñò! Óäàëåíèå íåâîçìîæíî.\n";
            }
            break;
        case 3:
            cout << stack.toString() << endl;
            break;
        case 4:
            stack.clearStack();
            cout << "Ñòåê î÷èùåí.\n";
            break;
        case 5:
            cout << "Âûõîä èç ïðîãðàììû.\n";
            return 0;
        default:
            cout << "Íåâåðíûé âûáîð! Ïîæàëóéñòà, ïîïðîáóéòå ñíîâà.\n";
        }
    }
}
