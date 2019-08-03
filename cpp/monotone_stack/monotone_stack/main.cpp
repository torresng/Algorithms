#include <iostream>
#include <vector>

using namespace std;

const int N = 100010;

int stk[N], tt;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while (tt && stk[tt] >= x) {
            tt--;
        }
        if (tt) {
            printf("%d ", stk[tt]);
        } else {
            printf("-1 ");
        }
        stk[++tt] = x;
    }

    return 0;
}
