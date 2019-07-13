#include <iostream>

using namespace std;

const int N = 1000010;
int tmp[N];

void merge_sort(int arr[], int l, int r) {
    if (l == r) {
        return;
    }

    int mid = (l + r) >> 1;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);

    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            tmp[k++] = arr[i++];
        } else {
            tmp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        tmp[k++] = arr[i++];
    }
    while (j <= r) {
        tmp[k++] = arr[j++];
    }

    for (i = l, k = 0; i <= r; ++i, ++k) {
        arr[i] = tmp[k];
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[N];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    merge_sort(arr, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

    return 0;
}
