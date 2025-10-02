/*
#include <iostream>

void Merge(int *arr, int left, int mid, int right){
    int i = left;
    int j = mid + 1;
    int k = left;
    int temp[100]; // temp[r - l]
    while ((i <= mid) && (j <= right)){
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
    while (j < right){
        temp[k++] = arr[j++];
    }
    for (int idx = left; idx < right; ++idx){
        arr[idx] = temp[idx];
    }
}

void Merge_sort(int *arr, int left, int right){
    if (left >= right){
        return;
    }
    int mid = left + (right - left) / 2;
    Merge_sort(arr, left, mid);
    Merge_sort(arr, mid + 1, right);
    Merge(arr, left, mid, right);
}

int main(){
    int n;
    std::cin >> n;
    int arr[100];
    for (size_t i = 0; i < n; ++i){
        std::cin >> arr[i];
    }
    Merge_sort(arr, 0, n - 1);
    for (size_t i = 0; i < n; ++i){
        std::cout << arr[i] << " ";
    }
}
*/

#include <iostream>
using namespace std;

// Максимальный размер массива
const int MAXN = 100000; // поменяйте на нужное значение

// Вспомогательный массив для слияния
int temp[MAXN];

// Слияние диапазона [left, mid] и [mid+1, right]
void merge_ranges(int arr[], int left, int mid, int right) {
    int i = left;      // первый элемент левой части
    int j = mid + 1;   // первый элемент правой части
    int k = left;        // индекс в временном массиве

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    // копируем оставшиеся элементы
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    // копируем обратно в исходный массив
    for (int idx = left; idx <= right; ++idx) {
        arr[idx] = temp[idx];
    }
}

// Рекурсивная сортировка диапазона [left, right]
void mergeSort(int arr[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge_ranges(arr, left, mid, right);
}

int main() {
    // Пример: считываем размер и элементы
    int n;
    std::cout << "Введите количество элементов (<= " << MAXN << "): ";
    std::cin >> n;
    if (n < 0 || n > MAXN) {
        std::cerr << "Некорректный размер массива\n";
        return 1;
    }

    std::cout << "Введите элементы:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> temp[i]; // временно используем temp как основной массив
    }

    // Поскольку temp используется как вспомогательный массив, копируем в обычный массив
    int arr[MAXN];
    for (int i = 0; i < n; ++i) arr[i] = temp[i];

    mergeSort(arr, 0, n - 1);

    std::cout << "Отсортированный массив:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << (i + 1 == n ? '\n' : ' ');
    }

    return 0;
}