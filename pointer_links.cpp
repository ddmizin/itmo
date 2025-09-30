#include <iostream>

void Swap(int* x, int* y);

int main(){
    uint64_t x = 10;
    uint64_t y = 10;
    std::cout << &x << " " << &y << '\n'; // &x и &y - адреса x и y
    std::cout << *(&x) << " " << *(&y) << '\n';
    uint64_t* x_ptr = &x; // p - переменнаяя, которая хранит адрес x
    uint64_t p = *x_ptr;
    std::cout << *x_ptr << "==" << p;
    int i = 256;
    int j = 128;
    Swap(&i, &j);
    std:: cout << '\n' << i << " " << j << '\n';
}

void Swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
