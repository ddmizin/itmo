#include <iostream>

const int MAXN = 100000000;
uint32_t temp[MAXN];
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

void Merge(uint32_t *arr, uint64_t left, uint64_t mid, uint64_t right){
    uint64_t i = left;
    uint64_t j = mid + 1;
    uint64_t c = left;
    while ((i <= mid) && (j <= right)){
        if (arr[i] <= arr[j]){
            temp[c++] = arr[i++];
        }
        else {
            temp[c++] = arr[j++];
        }
    }
    while (i <= mid){
        temp[c++] = arr[i++];
    }
    while (j <= right){
        temp[c++] = arr[j++];
    }
    for (uint64_t idx = left; idx <= right; ++idx){
        arr[idx] = temp[idx];
    }
}

void Merge_sort(uint32_t *arr, uint64_t left, uint64_t right){
    if (left >= right){
        return;
    }
    uint64_t mid = left + (right - left) / 2;
    Merge_sort(arr, left, mid);
    Merge_sort(arr, mid + 1, right);
    Merge(arr, left, mid, right);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    uint32_t n, k, a, b;
    std::cin >> n >> k >> a >> b;

    uint32_t arr[n];

    for (uint32_t i = 0; i < n; i++) {
        arr[i] = nextRand32(a, b);  // генерируем i-й элемент
    }

    // здесь будет ваш алгоритм
    Merge_sort(arr, 0, n - 1);
    std::cout << arr[k - 1];
}