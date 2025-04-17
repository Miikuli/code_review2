/* Элементами контейнеров являются целые числа. Для
заполнения контейнера использовать итератор и конструктор соответствующего контейнера,
для вывода элементов использовать итератор (для вывода элементов в обратном порядке
использовать обратные итераторы, возвращаемые функциями-членами rbegin и rend)
Обязательно наличие дружественного интерфейса. Ввод данных организовать
разными способами (с клавиатуры, рандом, из файла)


 Дан дек D с нечетным количеством элементов N (≥ 5). Добавить в начало дека пять
его средних элементов в исходном порядке. Использовать один вызов функции-члена insert. */

#include "deque_operations.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

void insertMiddleElements(deque<int>& d) {
    if (d.size() < 5 || d.size() % 2 == 0) {
        throw invalid_argument("Deque size must be odd and >= 5");
    }

    // Используем итераторы для получения средних элементов
    auto middle = d.begin() + d.size() / 2;
    deque<int> middleElements(middle - 2, middle + 3);

    // Вставляем с помощью итераторов
    d.insert(d.begin(), middleElements.begin(), middleElements.end());
}

deque<int> createDequeFromKeyboard() {
    int count;
    cout << "Введите количество целых чисел (нечетное и >= 5): ";
    cin >> count;

    while (count < 5 || count % 2 == 0) {
        cout << "Количество должно быть нечетным и >= 5. Повторите ввод: ";
        cin >> count;
    }

    deque<int> d;
    cout << "Введите " << count << " целых чисел:" << endl;

    // Используем итератор вставки
    istream_iterator<int> input_iter(cin);
    istream_iterator<int> end_of_input;
    copy_n(input_iter, count, back_inserter(d));

    return d;
}

deque<int> createRandomDeque(int count) {
    deque<int> d;
    srand(static_cast<unsigned>(time(nullptr)));

    // Генерируем случайные числа с помощью generate_n
    generate_n(back_inserter(d), count, []() { return rand() % 100; });

    return d;
}

deque<int> createDequeFromFile(const string& filename) {
    deque<int> d;
    ifstream infile(filename);

    if (!infile.is_open()) {
        throw runtime_error("Не удалось открыть файл: " + filename);
    }

    // Используем итераторы для чтения из файла
    istream_iterator<int> input_iter(infile);
    istream_iterator<int> end_of_input;
    copy(input_iter, end_of_input, back_inserter(d));

    if (d.size() < 5 || d.size() % 2 == 0) {
        throw invalid_argument("Количество чисел в файле должно быть нечетным и >= 5");
    }

    return d;
}

void printDequeWithIterators(const deque<int>& d) {
    // Вывод в прямом порядке с использованием begin()/end()
    cout << "Прямой порядок (begin -> end): ";
    for (auto it = d.begin(); it != d.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Вывод в обратном порядке с использованием rbegin()/rend()
    cout << "Обратный порядок (rbegin -> rend): ";
    for (auto rit = d.rbegin(); rit != d.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;
}
