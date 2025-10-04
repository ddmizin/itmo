#include <iostream>
#include <cstdint>

uint32_t cur = 0;  // беззнаковое 32-битное число

// Генератор 24-битного числа
uint32_t nextRand24(uint32_t a, uint32_t b) {
    cur = cur * a + b;      // вычисляется с переполнениями по модулю 2^32
    return cur >> 8;         // число от 0 до 2^24 - 1
}

// Генератор 32-битного числа на основе двух 24-битных
uint32_t nextRand32(uint32_t a, uint32_t b) {
    uint32_t x = nextRand24(a, b);
    uint32_t y = nextRand24(a, b);
    return (x << 8) ^ y;     // число от 0 до 2^32 - 1
}

int Partition(uint32_t arr[], uint64_t l, uint64_t r, uint64_t k){
    uint64_t pivot = arr[(l + r) / 2];
    uint64_t i = l - 1;
    uint64_t j = r + 1;
    while (true) {
        do { ++i; } while (arr[i] < pivot);
        do { --j; } while (arr[j] > pivot);
        if (i >= j) {
            return j;
        }
        std::swap(arr[i], arr[j]);
    }
}

void Quick_sort(uint32_t arr[], uint64_t l, uint64_t r, uint64_t k){
    if (l < r){
        uint64_t pivot = Partition(arr, l, r, k);
        if (k - 1 <= pivot) {
            Quick_sort(arr, l, pivot, k);
        }
        else {
            Quick_sort(arr, pivot + 1, r, k);
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    uint32_t n, k, a, b;
    std::cin >> n >> k >> a >> b;

    uint32_t arr[n];

    for (uint32_t i = 0; i < n; i++) {
        arr[i] = nextRand32(a, b);  // генерируем i-й элемент
    }

    // здесь будет ваш алгоритм
    Quick_sort(arr, 0, n - 1, k);
    std::cout << arr[k - 1];
}