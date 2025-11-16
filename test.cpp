#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int W, n;
    std::cin >> W >> n;
    
    std::vector <int> weights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> weights[i];
    }
    
    std::vector <int> d(W + 1, 0);
    
    for (int i = 0; i < n; i++) {
        int w = weights[i];
        for (int j = W; j >= w; j--) {
            d[j] = std::max(d[j], d[j - w] + w);
        }
    }
    std::cout << d[W];
}