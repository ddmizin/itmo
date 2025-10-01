/*#include <iostream>

void Merge(int *arr, int* p[][2], int l, int mid, int r){
    int i = 0;
    int j = 0;
    while ((l + i < mid) && (mid + j < r)){
        if (p[l + i][0] < p[mid + j][0]){
            arr[i + j] = l + i;
            ++i;
        }
        else {
            arr[i + j] = mid + j;
            ++j;
        }
    }
    while (l + i < mid){
        arr[i + j] = l + i;
        ++i;
    }
    while (mid + j < r){
        arr[i + j] = mid + j;
        ++j;
    }
}

void Merge_sort(int *arr, int* p[][2], int l, int r){
    if (l + 1 >= r){
        return;
    }
    int mid = (l + r) / 2;
    Merge_sort(arr, p, l, mid);
    Merge_sort(arr, p, mid, r);
    Merge(arr, p, l, mid, r);
}

int main(){
    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i){
        arr[i] = i;
    }
    int p[n][2];
    for (size_t i = 0; i < n; ++i){
        std::cin >> p[i][0] >> p[i][1];
    }
    Merge_sort(arr, p, 0, n);
    for (size_t i = 0; i < n; ++i){
        std::cout << arr[i] + 1 << " ";
    }
}
*/
