#include <iostream>

struct Point {
    int x;
    int y;
} ;

struct Rect {
    Point a;
    Point b;
} ;

int main(){
    Point p = {10, 20};
    Point pt;
    pt.x = 200;
    pt.y = 250;
    Rect rect = {{1, 2}, {3, 4}};
    rect.a = {5, 6};
    rect.b = {7, 8};
}
