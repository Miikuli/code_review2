/* Элементами контейнеров являются целые числа. Для
заполнения контейнера использовать итератор и конструктор соответствующего контейнера,
для вывода элементов использовать итератор (для вывода элементов в обратном порядке
использовать обратные итераторы, возвращаемые функциями-членами rbegin и rend)
Обязательно наличие дружественного интерфейса. Ввод данных организовать
разными способами (с клавиатуры, рандом, из файла)


 Дан дек D с нечетным количеством элементов N (≥ 5). Добавить в начало дека пять
его средних элементов в исходном порядке. Использовать один вызов функции-члена insert. */

#include "deque_operations.h"

int main() {
    setlocale(LC_ALL, "ru");
    int choice;
    cout << "Выберите метод ввода данных:\n"
        << "1. Ввод с клавиатуры\n"
        << "2. Случайные числа\n"
        << "3. Чтение из файла\n"
        << "Ваш выбор: ";
    cin >> choice;

    deque<int> d;

    try {
        switch (choice) {
        case 1:
            d = createDequeFromKeyboard();
            break;
        case 2: {
            int count;
            cout << "Введите количество чисел (нечетное и >= 5): ";
            cin >> count;
            while (count < 5 || count % 2 == 0) {
                cout << "Количество должно быть нечетным и >= 5. Повторите ввод: ";
                cin >> count;
            }
            d = createRandomDeque(count);
            break;
        }
        case 3:
            d = createDequeFromFile();
            break;
        default:
            cerr << "Некорректный выбор." << endl;
            return 1;
        }

        cout << "\nИсходный дек:\n";
        printDequeWithIterators(d);

        insertMiddleElements(d);

        cout << "\nДек после вставки средних элементов:\n";
        printDequeWithIterators(d);

    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }

    return 0;
}
