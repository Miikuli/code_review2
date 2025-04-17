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
        cout << "�������� ����. ����������, ������� ����� �����.\n";
    }
}

void displayMenu() {
    cout << "\n����:\n"
        << "1. �������� ������� � ����\n"
        << "2. ������� ������� �� �����\n"
        << "3. ������� �������� �����\n"
        << "4. �������� ����\n"
        << "5. �����\n";
}

int main() {
    Stack stack;

    while (true) {
        displayMenu();
        int choice = getValidInput("������� ��� �����: ");

        switch (choice) {
        case 1: {
            int value = getValidInput("������� ����� ��� ���������� � ����: ");
            addElementAndPrintAddress(stack, value);
            break;
        }
        case 2:
            if (!stack.pop()) {
                cout << "���� ����! �������� ����������.\n";
            }
            break;
        case 3:
            cout << stack.toString() << endl;
            break;
        case 4:
            stack.clearStack();
            cout << "���� ������.\n";
            break;
        case 5:
            cout << "����� �� ���������.\n";
            return 0;
        default:
            cout << "�������� �����! ����������, ���������� �����.\n";
        }
    }
}