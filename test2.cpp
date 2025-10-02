#include <iostream>
#include <cstdint>

const int MAXN = 1000000;  // максимум n по условию
uint32_t arr[MAXN];
uint32_t temp[MAXN];
uint64_t result = 0;

uint32_t cur = 0;              // текущее значение генератора

// Генератор 24-битных чисел по условию задачи
uint32_t nextRand24(uint32_t a, uint32_t b) {
    // 32-битные переполнения (uint32_t автоматически усекает до 2^32)
    cur = cur * a + b;
    return cur >> 8;  // берём старшие 24 бита (сдвиг вправо на 8)
}

void Merge(uint32_t *arr, uint64_t left, uint64_t mid, uint64_t right){
    uint64_t i = left;
    uint64_t j = mid + 1;
    uint64_t k = left;
    while ((i <= mid) && (j <= right)){
        if (arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            result += (mid - i + 1);
        }
    }
    while (i <= mid){
        temp[k++] = arr[i++];
    }
    while (j <= right){
        temp[k++] = arr[j++];
    }
    for (int idx = left; idx <= right; ++idx){
        arr[idx] = temp[idx];
    }
}

void Merge_sort(uint32_t *arr, uint64_t left, uint64_t right){
    if (left >= right){
        return;
    }
    int mid = left + (right - left) / 2;
    Merge_sort(arr, left, mid);
    Merge_sort(arr, mid + 1, right);
    Merge(arr, left, mid, right);
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    uint32_t n, m, a, b;
    std::cin >> n >> m >> a >> b;

    // Генерируем n элементов
    for (uint32_t i = 0; i < n; i++) {
        uint32_t x = nextRand24(a, b) % m; // получаем 24-битное значение по модулю m
        arr[i] = x;                        // записываем в массив
    }

    // Далее используйте arr[0..n-1] для подсчёта инверсий
    Merge_sort(arr, 0, n - 1);
    std::cout << result;
}