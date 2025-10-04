/*
#include <iostream>
#include <algorithm>

void sort_by_counting(){
    int n;
    std::cin >> n;
    int A[100];
    int B[100];
    int curr = 0;
    int k = -100000;
    for (size_t i = 0; i < n; ++i){
        std::cin >> curr;
        A[i] = curr;
        k = std::max(k, curr);
    }
    std::cout << '\n';
    int P[100] = {0};
    for (size_t i = 0; i < n; ++i){
        P[A[i]] += 1;
    }
    for (size_t i = 1; i <= k; ++i) {
        P[i] += P[i - 1];
    }
    for (size_t i = n; i > 0; --i){
        B[P[A[i - 1]] - 1] = A[i - 1];
        std::cout << P[A[i - 1]] - 1 << " ";
        --P[A[i - 1]];
    }
    std::cout << '\n';
    for (size_t i = 0; i < n; ++i){
        std::cout << B[i] << " ";
    }
}

int main(){
    sort_by_counting();
}

*/
#include <iostream>

static const int MAX_N = 100000;
static const int MAX_R = 100;

void step_by_step_positions_no_dynamic() {
    int n;
    if (!(std::cin >> n)) return;

    // freq хранит текущее количество элементов каждого рейтинга
    int freq[MAX_R + 1];
    for (int i = 0; i <= MAX_R; ++i) freq[i] = 0;

    // Вспомогательный массив для вывода итоговой последовательности (не обязателен)
    // Мы не используем его здесь, чтобы соответствовать ограничению.

    for (int i = 0; i < n; ++i) {
        int r;
        std::cin >> r;

        // количество элементов меньше r
        int less = 0;
        for (int v = 1; v < r; ++v) {
            less += freq[v];
        }
        // количество элементов равных r
        int equal = freq[r];

        int pos = less + equal; // правая позиция среди равных
        std::cout << pos;
        if (i + 1 < n) std::cout << ' ';

        // обновляем freq
        freq[r] += 1;
    }

    std::cout << '\n';
}

int main() {
    step_by_step_positions_no_dynamic();
    return 0;
}