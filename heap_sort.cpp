#include <iostream>
#include <utility>

void sift_down(size_t i, int arr[], int n){
    int min;
    while (2 * i + 1 < n){
        min = i;
        if (arr[2 * i + 1] < arr[min]){
            min = 2 * i + 1;
        }
        if ((2 * i + 2 <= n) && (arr[2 * i + 2] < arr[min])){
            min = 2 * i + 2;
        }
        if (min == i){
            break;
        }
        std::swap(arr[min], arr[i]);
        i = min;
    }
}

void extract_min(int arr[], int n){
    std::swap(arr[0], arr[n]);
    n -= 1;
    sift_down(0, arr[], n);
}

int main(){
    int n;
    std::cin >> n;
    int arr[n];
    for (size_t i = 0; i < n; ++i){
        std::cin >> arr[i];
    }
    for (int i = n / 2 - 1; i >= 0; --i){
        sift_down(i, arr[], n);
    }
    for (int i = 0; i < n; ++i){
        extract_min(arr[], n);
    }
}