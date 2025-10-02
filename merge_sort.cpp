#include <iostream>

void Merge(int *arr, int l, int mid, int r){
    int i = l;
    int j = mid + 1;
    int k = l;
    int temp[100]; // temp[r - l]
    while ((i <= mid) && (j <= r)){
        if (arr[i] < arr[j]){
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }
    while (i < mid){
        temp[k++] = arr[i++];
    }
    while (j < r){
        temp[k++] = arr[j++];
    }
    for (int idx = l; idx < r; ++idx){
        arr[idx] = temp[idx];
    }
}

void Merge_sort(int *arr, int l, int r){
    if (l >= r){
        return;
    }
    int mid = l + (r - l) / 2;
    Merge_sort(arr, l, mid);
    Merge_sort(arr, mid + 1, r);
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