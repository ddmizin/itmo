#include <cstdint>
#include <iostream>

const int MAXN = 1000000;  // максимум n по условию
uint32_t arr[MAXN]; 

uint32_t cur = 0;              // текущее значение генератора
// Генератор 24-битных чисел по условию задачи
uint32_t nextRand24(uint32_t a, uint32_t b) {
    // 32-битные переполнения (uint32_t автоматически усекает до 2^32)
    cur = cur * a + b;
    return cur >> 8;  // берём старшие 24 бита (сдвиг вправо на 8)
}

uint64_t Merge(uint32_t *arr, uint64_t l, uint64_t mid, uint64_t r){
    int i = 0;
    int j = 0;
    uint64_t result = 0;
    uint32_t temp[r - l]; // temp[r - l]
    while ((l + i < mid) && (mid + j < r)){
        if (arr[l + i] < arr[mid + j]){
            temp[i + j] = arr[l + i];
            ++i;
        }
        else {
            temp[i + j] = arr[mid + j];
            ++j;
            result += (mid - i + 1);
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
    return result;
}

uint64_t Merge_sort(uint32_t *arr, uint64_t l, uint64_t r){
    uint64_t result = 0;
    if (l < r){
    

        int mid = (l + r) / 2;
        result += Merge_sort(arr, l, mid);
        result += Merge_sort(arr, mid, r);
        result += Merge(arr, l, mid, r);
        return result;
    }
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
    uint64_t result = Merge_sort(arr, 0, n - 1);
    std::cout << result;
}