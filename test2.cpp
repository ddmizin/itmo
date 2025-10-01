#include <iostream>


bool pairs(int p1[], int p2[]){
    if (p1[0] < p2[0]){
        return true;
    }
    else if (p1[0] > p2[0]){
        return false;
    }
    else if (p1[1] > p2[1]){
        return false;
    }
    else{
        return true;
    }
}


void Merge(int arr[], int p[][2], int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int Left[n1];
    int Right[n2];
    for (size_t i = 0; i < n1; ++i){
        Left[i] = arr[l + i];
    }
    for (size_t i = 0; i < n2; ++i){
        Right[i] = arr[mid + i + 1];
    }
    int i = 0;
    int j = 0;
    int t = l;
    while (i < n1 && j < n2) {
        if (pairs(p[Left[i] - 1], p[Right[j] - 1])){
            arr[t] = Left[i];
            i++;
        } else {
            arr[t] = Right[j];
            j++;
        }
        ++t;
    }
    while (i < n1) {
        arr[t] = Left[i];
        ++i;
        ++t;
    }    
    while (j < n2) {
        arr[t] = Right[j];
        ++j;
        ++t;
    }
}

void Merge_sort(int arr[], int p[][2], int l, int r){
    if (l < r){
        int mid = (l + r) / 2;
        Merge_sort(arr, p, l, mid);
        Merge_sort(arr, p, mid + 1, r);
        Merge(arr, p, l, mid, r);
    }
}

int main(){
    int n;
    std::cin >> n;
    int arrindex[n];
    for (int i = 0; i < n; ++i){
        arrindex[i] = i + 1;
    }
    int p[n][2];
    for (size_t i = 0; i < n; ++i){
        std::cin >> p[i][0] >> p[i][1];
    }
    Merge_sort(arrindex, p, 0, n - 1);
    for (size_t i = 0; i < n; ++i){
        std::cout << arrindex[i] << " ";
    }
}