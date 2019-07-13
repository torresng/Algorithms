#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1000010;
int tmp[N];

LL merge_sort(int arr[], int l, int r) {
    if (l == r) {
        return 0;
    }

    int mid = (l + r) >> 1;
    LL res = merge_sort(arr, l, mid) + merge_sort(arr, mid + 1, r);

    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            tmp[k++] = arr[i++];
        } else {
            tmp[k++] = arr[j++];
            res += mid - i + 1;
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

    return res;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[N];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    cout << merge_sort(arr, 0, n - 1) << endl;

    return 0;
}
