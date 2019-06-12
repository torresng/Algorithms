#include <cstdio>

using namespace std;

const int N = 1e6 + 10;

int arr[N], tmp[N];

void merge_sort(int arr[], int l, int r) {
    if (l >= r) {
        return;
    }

    int mid = (l + r) >> 1;

    merge_sort(arr, l, mid), merge_sort(arr, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
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

    for (i = l, j = 0; i <= r; ++i, ++j) {
        arr[i] = tmp[j];
    }
}

int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    merge_sort(arr, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

    return 0;
}
