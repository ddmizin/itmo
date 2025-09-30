#include <iostream>
#include <utility>

int Partition(int arr[], int l, int r){
    int pivot = arr[(l + r) / 2];
    int i = l - 1;
    int j = r + 1;
    while (true) {
        do { ++i; } while (arr[i] < pivot);
        do { --j; } while (arr[j] > pivot);
        if (i >= j) {
            return j;
        }
        std::swap(arr[i], arr[j]);
    }
}

void Quick_sort(int arr[], int l, int r){
    if (l < r){
        int p = Partition(arr, l, r);
        Quick_sort(arr, l, p);
        Quick_sort(arr, p + 1, r);
    }
}

int main(){
    int n;
    std::cin >> n;
    int arr[100];
    for (size_t i = 0; i < n; ++i){
        std::cin >> arr[i];
    }
    Quick_sort(arr, 0, n - 1);
    for (size_t i = 0; i < n; ++i){
        std::cout << arr[i] << " ";
    }
}