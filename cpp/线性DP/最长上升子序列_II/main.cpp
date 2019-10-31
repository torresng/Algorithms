#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100010;

int n;
int a[N];
int q[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int len = 0;
    q[0] = -2e9;
    for (int i = 0; i < n; i++) {
        int l = 0, r = len;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (q[mid] < a[i]) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        len = max(len, r + 1);
        q[r + 1] = a[i];

        cout << r + 1 << endl;
        cout << len << ' ' << q[len] << endl;
    }

    printf("%d\n", len);

    return 0;
}
