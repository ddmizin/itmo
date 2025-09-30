#include <iostream>

int main(){
    // -------------------------------------if
    if (condition1) { // <, <=, >, >=, &&, ||
    // случай, когда condition1 истинно
    } else if (condition2) {
    // случай, когда condition1 ложно, а condition2 истинно
    } else if (condition3) {
    // случай, когда condition1 и condition2 ложны, а condition3 истинно
    } else {
    // случай, когда condition1, condition2 и condition3 ложны
    }
    char operation;
    // -----------------------------------switch
    switch (operation) {
        case '+':
            break;  // если не написать этот break, программа просто пойдёт дальше в код следующего блока case
        case '-':
            break;
        case '*':
            break;
        case '/':
            break;
        case ':':
            break;
        case '%':
            break;
        default:  // здесь обрабатывается случай, когда ни один case не сработал.
    }
    // -----------------------------------do-while
    int n = 1;
    do {
        std::cout << n << "\t" << n * n << "\n";
        ++n;
    } while (n <= 10);
    // --------------------------------------for
    for (initialization; condition; action) {
        // тело цикла
    }
    // -------------------------------------range-based for
    std::string line;
    std::getline(std::cin, line);
    for (char symbol : line) {
        std::cout << symbol << "\t" << static_cast<int>(symbol) << "\n";
    }
}