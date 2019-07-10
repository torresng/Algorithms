#include <iostream>
#include <vector>

using namespace std;

const int N = 100010;

int a[N], b[N];

void insert(int l, int r, int c) {
    b[l] += c;
    b[r + 1] -= c;
}

int main(void) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n; ++i) {
        insert(i, i, a[i]);
    }

    int l, r, c;
    while (m--) {
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }

    for (int i = 1; i <= n; ++i) {
        b[i] += b[i - 1];
    }

    for (int i = 1; i <= n; ++i) {
        printf("%d ", b[i]);
    }

    return 0;
}

/*
int main(void) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);  // 存放原數組
    }

    for (int i = 1; i <= n; ++i) {
        b[i] = a[i] - a[i - 1]; // 構造差分
    }

    int l, r, c;
    while (m--) {
        scanf("%d%d%d", &l, &r, &c);
        b[l] += c;     // 將1和以後加c
        b[r + 1] -= c; // 將r之後-c
    }

    for (int i = 1; i <= n; ++i) {
        b[i] += b[i - 1];  // 將差分改為原數組
        printf("%d ", b[i]);
    }

    return 0;
}
*/
