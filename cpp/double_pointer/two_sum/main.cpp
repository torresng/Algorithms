#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, x;
    scanf("%d%d%d", &n, &m, &x);
    vector<int> a(n);
    vector<int> b(n);

    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < m; ++i) {
        scanf("%d", &b[i]);
    }

    for(int i = 0, j = m - 1; i < n; ++i) {
        while(j >= 0 && a[i] + b[j] > x) { --j; }
        if(a[i] + b[j] == x) printf("%d %d\n", i, j);
    }

    return 0;
}
