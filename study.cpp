#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <utility>
#include <tuple>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    std::cout << a << " " << b << " " << c;
}

int main2() {
    char c = '1'; // символ
    bool b = true; // логическая переменная, принимает значения false и true
    int i = 42; // целое число (занимает, как правило, 4 байта)
    short int si = 17; // короткое целое (занимает 2 байта)
    long li = 12321321312; // длинное целое (как правило, 8 байт)
    long long lli = 12321321312; // длинное целое (как правило, 16 байт)
    float f = 2.71828; // дробное число с плавающей запятой (4 байта)
    double d = 3.141592; // дробное число двойной точности (8 байт)
    long double ld = 1e15; // длинное дробное (как правило, 16 байт)
}

int main3() {
    unsigned int ui = 4294967295; // 2^32 - 1
}

int main4() {
    int a = 6, b = 4;
    double q = static_cast<double>(a) / b; // 1.5
}

int main5() {
    std::string a = "Hello, ";
    std::string b = "world!";
    std::string c = a + b; // Hello, world!
}

// ----------------- if, switch
int main6() {
    int x;
    std::cin >> x;
    if (x <= 0) {
        std::cout << "zero or negative\n";
    } else if (x == 1) {
        std::cout << "one\n";
    } else if (x == 2) {
        std::cout << "two\n";
    } else {
        std::cout << "many\n";
    }
}

int main7() {
    int64_t a, b;
    char operation;
    std::cin >> a >> operation >> b;

    int64_t result;
    switch (operation) {
        case '+':
            result = a + b;
            break; // если не написать этот break, программа просто пойдёт дальше в код следующего блока case
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
        case ':':
            result = a / b;
            break;
        case '%':
            result = a % b;
            break;
        default: // здесь обрабатывается случай, когда ни один case не сработал.
            result = 0;
    }

    std::cout << result << "\n";
}

// ----------- сравнение дробных чисел

int main8() {
    double delta = 0.000001;

    double x = 0.1, y = 0.2;
    double sum = x + y;

    if (std::abs(sum - 0.3) < delta) {
        std::cout << "EQUAL ";
    } else {
        std::cout << "NOT EQUAL ";
    }

    std::cout << sum << "\n";
}

// ------------------ while, for, do-while, range-based

int main9() {
    int n = 1;
    while (n <= 10) {
        std::cout << n << "\t" << n * n << "\n"; // выводим число и его квадрат через табуляцию
        ++n;
    }
}

int main10() {
    int n = 1;
    do {
        std::cout << n << "\t" << n * n << "\n";
        ++n;
    } while (n <= 10);
}

int main11() {
    for (int i = 1; i <= 10; ++i) {
        std::cout << i << "\t" << i * i << "\n";
    }
}

int main12() {
    std::string line;
    std::getline(std::cin, line);
    for (char symbol: line) {
        std::cout << symbol << "\t" << static_cast<int>(symbol) << "\n";
    }
}

int main13() {
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            std::cout << i * j << "\t";
        }
        std::cout << "\n";
    }
}

int main14() {
    // Считывание до конца ввода
    std::string name;
    while (std::getline(std::cin, name)) {
        std::cout << "Hello, " << name << "!\n";
    }
}

// ------------------ std::vector, std::string
int main15() {
    std::vector<int> data = {1, 2, 3, 4, 5};
    for (int elem: data) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}

int main16() {
    std::vector<std::string> v1; // пустой вектор строк
    std::vector<std::string> v2(5); // вектор из пяти пустых строк
    std::vector<std::string> v3(5, "hello"); // вектор из пяти строк "hello"
    std::vector<int> data = {1, 2, 3, 4, 5};
    int a = data[0]; // начальный элемент вектора
    int b = data[4]; // последний элемент вектора (в нём пять элементов)
    data[2] = -3;
    std::cout << data.size() << "\n"; // общее количество элементов в векторе
    std::vector<int> data2 = {1, 2, 3, 4, 5};
    std::cout << data2[42] << "\n"; // неопределённое поведение: может произойти всё что угодно
    std::cout << data2.at(0) << "\n"; // напечатается 1
    std::cout << data2.at(42) << "\n";
    // произойдёт исключение std::out_of_range — его можно будет перехватить и обработать
    std::vector<int> data3 = {1, 2, 3, 4, 5};
    std::cout << data3.front() << "\n"; // то же, что data[0]
    std::cout << data3.back() << "\n"; // то же, что data[data.size() - 1]
    for (size_t i = 0; i != data3.size(); ++i) {
        std::cout << data[i] << " ";
    }
}

int main17() {
    int x;
    std::vector<int> data;
    while (std::cin >> x) {
        // читаем числа, пока не закончится ввод
        data.push_back(x); // добавляем очередное число в вектор
    }

    while (!data.empty() && data.back() == 0) {
        // Пока вектор не пуст и последний элемент равен нулю
        data.pop_back(); // удаляем этот нулевой элемент
    }
}

int main18() {
    size_t m, n;
    std::cin >> m >> n; // число строк и столбцов

    // создаём матрицу matrix из m строк, каждая из которых — вектор из n нулей
    std::vector<std::vector<int> > matrix(m, std::vector<int>(n));

    for (size_t i = 0; i != m; ++i) {
        for (size_t j = 0; j != n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    // напечатаем матрицу, выводя элементы через табуляцию
    for (size_t i = 0; i != m; ++i) {
        for (size_t j = 0; j != n; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

// сортировка вектора
int main19() {
    std::vector<int> data = {3, 1, 4, 1, 5, 9, 2, 6};

    // Сортировка диапазона вектора от начала до конца
    std::sort(data.begin(), data.end());

    // получим вектор 1, 1, 2, 3, 4, 5, 6, 9
    std::sort(data.rbegin(), data.rend()); // 9, 6, 5, 4, 3, 2, 1, 1
}

// ------------ строки
int main20() {
    std::string s = "Some string";

    // приписывание символов и строк
    s += ' '; // добавляем отдельный символ в конец, это аналог push_back
    s += "functions"; // добавляем строку в конец
    std::cout << s << "\n"; // Some string functions

    // выделение подстроки
    // подстрока "string" из 6 символов начиная с 5-й позиции
    std::string sub1 = s.substr(5, 6);
    // подстрока "functions" с 12-й позиции и до конца
    std::string sub2 = s.substr(12);

    // поиск символа или подстроки
    size_t pos1 = s.find(' '); // позиция первого пробела, в данном случае 4
    size_t pos2 = s.find(' ', pos1 + 1); // позиция следующего пробела (11)
    size_t pos3 = s.find("str"); // вернётся 5
    size_t pos4 = s.find("#"); // вернётся std::string::npos
}

int main21() {
    std::string s = "Some string functions";

    // вставка подстроки
    s.insert(5, "std::");
    std::cout << s << "\n"; // Some std::string functions

    // замена указанного диапазона на новую подстроку
    s.replace(0, 4, "Special");
    std::cout << s << "\n"; // Special std::string functions

    // удаление подстроки
    s.erase(8, 5); // Special string functions
}

// --------------------------------- Составные типы данных
enum class Color {
    White,
    Red,
    Orange,
    Blue,
};

int main22() {
    Color color1 = Color::Red;
    Color color2 = Color::Blue;
    int value = static_cast<int>(color2); // 3
    Color color3 = static_cast<Color>(2); // Color::Orange
}

// ------------- Структуры
struct Point {
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
    Color color; // пусть у нас будет цветная точка
};

int main23() {
    Point point1; // по умолчанию координаты будут нулевыми, а color никак не будет проинициализирован
    point1.color = Color::Blue;

    Point point2 = {1.4, -2.2, -3.98, Color::Red};
    // x = 1.4, y = -2.2, z = -3.98, color = Color::Red

    point2.z = 32; // обращаться к полям можно через точку
    point2.x += 2; // и вообще работать с ними как с обычными переменными
}

int main24() {
    Point point3 = {.x = 1.4, .y = -2.2, .z = -3.98};
    Point point4 = {.color = Color::Orange};
}

// ------------------------ Кортежи и пары
int main25() {
    // в угловых скобках нужно указывать два типа:
    std::pair<int, double> p = {42, 3.14};

    // обращаться к полям можно через .first и .second:
    std::cout << p.first << "\n"; // 42
    std::cout << p.second << "\n"; // 3.14
}

int main26() {
    std::tuple<int, double, Point> t = {42, 3.14, {.color = Color::Orange}};

    // тут уже нет полей .first и .second,
    // но есть стандартная функция std::get<>,
    // которая принимает в угловых скобках индекс элемента (индексация с нуля):
    std::cout << std::get<0>(t) << "\n"; // 42
    std::cout << std::get<1>(t) << "\n"; // 3.14
    std::cout << std::get<2>(t).x << "\n"; // 0.0

    // вызов std::get может появляться и слева от присваивания:
    std::get<2>(t).color = Color::Red;
}

int main27() {
    std::pair<std::string, int> p = {"hello", 42};
    auto [word, freq] = p; // word = "hello"; freq = 42;
}
