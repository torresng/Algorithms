#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1000010;

void quick_sort(int arr[], int l, int r) {
    if (l == r) {
        return;
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

    quick_sort(arr, l, j);
    quick_sort(arr, j + 1, r);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[N];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    quick_sort(arr, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

    return 0;
}
