#include <iostream>

using namespace std;

const int N = 100010;

int a[N], b[N];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int len = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        ++b[a[i]];
        while (j < i && b[a[i]] > 1) {
            --b[a[j++]];
        }
        len = max(len, i - j + 1);
    }
    printf("%d", len);

    return 0;
}
