#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdint>

int main() { 
    // ----------------------перевод тивов static_cast <data_type>
    int a = 6;
    int b = 4;
    double q = static_cast<double>(a) / b;  // 1.5
    // ----------------------модуль числа std::abs (<cmath>)
    std::cout << std::abs(-2);
    // ----------------------считывание до конца ввода
    int x;
    while (std::cin >> x) {
        // тело цикла
    }
    // ----------------------максиму/минимум из чисел
    int num1 = 10;
    int num2 = 25;
    int max_num = std::max(num1, num2); // (<algorithm>)
    int max_num = std::min(num1, num2);

    int16_t x = 1; // (<cstdint>)
    int64_t y = 2; // переменная, которая весит 64 бита
    uint16_t z = 3; // беззнаковая переменная, которая весит 16 бит
    
    // --------------------------------переменные в разных системах счислениях
    int a1 = 0242; // переменная в 8й системе счисления
    int a2 = 0x2A3; // переменная в 16й системе счисления
    int a3 = 0b10; // переменная в 2й системе счисления
}