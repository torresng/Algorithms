#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1000010;

int quick_sort(int arr[], int l, int r, int k) {
    if (l == r) {
        return arr[l];
    }

    int i = l - 1, j = r + 1, x = arr[(l + r) >> 1];
    while (i < j) {
        do {
            ++i;
        } while (arr[i] < x);
        do {
            --j;
        } while (arr[j] > x);
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    int si = j - l + 1;
    if (k <= si) {
        return quick_sort(arr, l, j, k);
    } else {
        return quick_sort(arr, j + 1, r, k - si);
    }
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    int arr[N];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    cout << quick_sort(arr, 0, n - 1, k) << endl;

    return 0;
}
