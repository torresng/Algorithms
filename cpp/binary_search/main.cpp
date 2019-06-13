#include <cassert>
#include <vector>

using namespace std;

bool check(int mid);
/**
 * 二分模板 - 版本1
 * 當我們將區間[l, r]划分成[l, mid]和[mid + 1, r]時，
 * 其更新操作是r = mid或者l = mid + 1，計算mid時不需要加1。
 */
int bSearch_1(int l, int r) {
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

/**
 * 二分模板 - 版本2
 * 當我們將區間[l, r]划分成[l, mid - 1]和[mid, r]時，
 * 其更新操作是r = mid - 1或者l = mid，此時為了防止死循環，計算mid時需要加1。
 */
int bSearch_2(int l, int r) {
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

/**
 * 二分查找，找到該值在數組中的下標，否則為-1
 */
int binarySearch(vector<int> &arr, int key) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

void test_case_1() {
    vector<int> arr{1, 2, 3, 4, 5, 6};
    int result;

    result = binarySearch(arr, 3);
    assert(result == 2);

    result = binarySearch(arr, 6);
    assert(result == 5);

    result = binarySearch(arr, 5);
    assert(result == 4);

    result = binarySearch(arr, 7);
    assert(result == -1);
}

// 查找第一个與key相等的元素
int findFirstEqual(vector<int> &arr, int key) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] >= key) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if (left < arr.size() && arr[left] == key) {
        return left;
    }
    return -1;
}

void test_case_2() {
    vector<int> arr{1, 1, 2, 2, 2, 5, 5, 6};
    int result;

    result = findFirstEqual(arr, 1);
    assert(result == 0);

    result = findFirstEqual(arr, 6);
    assert(result == 7);

    result = findFirstEqual(arr, 5);
    assert(result == 5);

    result = findFirstEqual(arr, 7);
    assert(result == -1);
}

// 查找最后一个與key相等的元素
int findLastEqual(vector<int> &arr, int key) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] > key) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if (right >= 0 && arr[right] == key) {
        return right;
    }
    return -1;
}

void test_case_3() {
    vector<int> arr{1, 1, 2, 2, 2, 5, 5, 6};
    int result;

    result = findLastEqual(arr, 1);
    assert(result == 1);

    result = findLastEqual(arr, 6);
    assert(result == 7);

    result = findLastEqual(arr, 5);
    assert(result == 6);

    result = findLastEqual(arr, 7);
    assert(result == -1);
}

// 查找最後一個等於或者小於key的元素
int findLastEqualSmaller(vector<int> &arr, int key) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] > key) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return right;
}

void test_case_4() {
    vector<int> arr{1, 1, 2, 2, 2, 5, 5, 6};
    int result;

    result = findLastEqualSmaller(arr, 1);
    assert(result == 1);

    result = findLastEqualSmaller(arr, 6);
    assert(result == 7);

    result = findLastEqualSmaller(arr, 5);
    assert(result == 6);

    result = findLastEqualSmaller(arr, 7);
    assert(result == 7);

    result = findLastEqualSmaller(arr, 4);
    assert(result == 4);
}

// 查找最後一個小於key的元素
int findLastSmaller(vector<int> &arr, int key) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] >= key) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return right;
}

void test_case_5() {
    vector<int> arr{1, 1, 2, 2, 2, 5, 5, 6};
    int result;

    result = findLastSmaller(arr, 1);
    assert(result == -1);

    result = findLastSmaller(arr, 6);
    assert(result == 6);

    result = findLastSmaller(arr, 5);
    assert(result == 4);

    result = findLastSmaller(arr, 7);
    assert(result == 7);

    result = findLastSmaller(arr, 4);
    assert(result == 4);
}

// 查找第一個等於或者大於key的元素
int findFirstEqualLarger(vector<int> &arr, int key) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] >= key) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

void test_case_6() {
    vector<int> arr{1, 1, 2, 2, 2, 5, 5, 6};
    int result;

    result = findFirstEqualLarger(arr, 1);
    assert(result == 0);

    result = findFirstEqualLarger(arr, 6);
    assert(result == 7);

    result = findFirstEqualLarger(arr, 5);
    assert(result == 5);

    result = findFirstEqualLarger(arr, 7);
    assert(result == 8);

    result = findFirstEqualLarger(arr, 4);
    assert(result == 5);
}

// 查找第一個大於key的元素
int findFirstLarger(vector<int> &arr, int key) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] > key) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

void test_case_7() {
    vector<int> arr{1, 1, 2, 2, 2, 5, 5, 6};
    int result;

    result = findFirstLarger(arr, 1);
    assert(result == 2);

    result = findFirstLarger(arr, 6);
    assert(result == 8);

    result = findFirstLarger(arr, 5);
    assert(result == 7);

    result = findFirstLarger(arr, 7);
    assert(result == 8);

    result = findFirstLarger(arr, 4);
    assert(result == 5);
}

// 二分查找變種總結
/*
while(left <= right) {
    int mid = (left + right) / 2;
    if(arr[mid] ? key) {
        //... right = mid - 1;
    } else {
        //... left = mid + 1;
    }
}
return xxx;
*/

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();
    test_case_5();
    test_case_6();
    test_case_7();

    return 0;
}
