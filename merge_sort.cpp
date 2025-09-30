#include <iostream>

void Merge(int *arr, int l, int mid, int r){
    int i = 0;
    int j = 0;
    int temp[100]; // temp[r - l]
    while ((l + i < mid) && (mid + j < r)){
        if (arr[l + i] < arr[mid + j]){
            temp[i + j] = arr[l + i];
            ++i;
        }
        else {
            temp[i + j] = arr[mid + j];
            ++j;
        }
    }
    while (l + i < mid){
        temp[i + j] = arr[l + i];
        ++i;
    }
    while (mid + j < r){
        temp[i + j] = arr[mid + j];
        ++j;
    }
    for (int k = 0; k < i + j; ++k){
        arr[l + k] = temp[k];
    }
}

void Merge_sort(int *arr, int l, int r){
    if (l + 1 >= r){
        return;
    }
    int mid = (l + r) / 2;
    Merge_sort(arr, l, mid);
    Merge_sort(arr, mid, r);
    Merge(arr, l, mid, r);
}

int main(){
    int n;
    std::cin >> n;
    int arr[100];
    for (size_t i = 0; i < n; ++i){
        std::cin >> arr[i];
    }
    Merge_sort(arr, 0, n);
    for (size_t i = 0; i < n; ++i){
        std::cout << arr[i] << " ";
    }
}