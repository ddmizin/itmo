#include <iostream>
#include <utility>
#include <string>
#include <vector>

void sift_down(size_t i, std::vector<int> arr, int len){
    while (true) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int max = i;
        if (l < len && arr[l] > arr[max]) {
            max = l;
        }
        if (r < len && arr[r] > arr[max]) {
            max = r;
        }
        if (max == i) {
            break;
        }
        std::swap(arr[i], arr[max]);
        i = max;
    }
}

void sort(std::vector<int> arr, int len){
    for (int end = len - 1; end > 0; --end){
        std::swap(arr[0], arr[end]);
        --len;
        sift_down(0, arr, len);
    }
}

int main(){
    int q;
    std::cin >> q;
    std::vector<int> arr;
    int len = 0;
    int result[100000];
    int len_res = 0;
    std::string command;
    for (size_t i = 0; i < q; ++i){
        std::cin >> command;
        if (command.substr(0, 5) == "Insert"){
            int new_n = std::stoi(command.substr(6, command.length() - 1));
            ++len;
            arr.push_back(new_n);
            sort(arr, len);
        }
        if (command.substr(0, 5) == "GetMin"){
            result[len_res] = arr[0];
            ++len_res;
            --len;
            arr.erase(arr.begin());
        }
        if (command.substr(0, 5) == "GetMax"){
            result[len_res] = arr.back();
            ++len_res;
            --len;
            arr.pop_back();
        }
    }

    for (int i = 0; i < len_res; ++i){
        std::cout << result[i] << '\n';
    }
}