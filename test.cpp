#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n;
    std::vector <int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::cin >> m;
    std::vector <int> b(m);
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }
    
    std::vector <std::vector <int>> d(n + 1, std::vector <int>(m + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                d[i][j] = d[i - 1][j - 1] + 1;
            } 
            else {
                d[i][j] = std::max(d[i - 1][j], d[i][j - 1]);
            }
        }
    }
    
    std::cout << d[n][m];
}