#include <iostream>

const int MAX_R = 100;

void step_by_step_positions_no_dynamic(int n) {
    int freq[MAX_R + 1];
    for (int i = 0; i <= MAX_R; ++i) {
        freq[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        int r;
        std::cin >> r;
        int less = 0;
        for (int v = 1; v < r; ++v) {
            less += freq[v];
        }
        int equal = freq[r];
        int pos = less + equal;
        std::cout << pos << " ";
        freq[r] += 1;
    }
}

int main() {
    int n;
    std::cin >> n;
    step_by_step_positions_no_dynamic(n);
}