#include <iostream>

int main(){
    enum Color {  // перечисление
        Red = 10,
        Green,
        Blue
    };
    Color color = Color::Blue;
}