#include <iostream>
#include <algorithm>

void sort_by_counting(int n, int k, int A[]){
    int B[100];
    std::cout << '\n';
    int P[100] = {0};
    for (size_t i = 0; i < n; ++i){
        P[A[i]] += 1;
    }
    for (size_t i = 1; i <= k; ++i) {
        P[i] += P[i - 1];
    }
    for (size_t i = 0; i < n; ++i){
        B[P[A[i]] - 1] = A[i];
        --P[A[i]];
        std::cout << P[A[i]] << " ";
    }
}

int main(){
    int n;
    std::cin >> n;
    int k = -1000000;
    int A[100];
    int curr = 0;
    for (size_t i = 0; i < n; ++i){
        std::cin >> curr;
        A[i] = curr;
        k = std::max(k, curr);
    }
    sort_by_counting(n, k, A);
}