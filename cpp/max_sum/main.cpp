#include <cassert>
#include <iostream>
#include <limits>
#include <set>
#include <vector>

using namespace std;

/*
 * 在arr查找連續和小於或等於k的最大值，O(n * lgn)
 */
int maxSumSeq(vector<int> &arr, int k) {
    if (arr.empty()) {
        return 0;
    }
    int ret = numeric_limits<int>::min();
    int curSum = 0;
    set<int> sum;
    sum.insert(0);
    for (int i = 0; i < arr.size(); ++i) {
        curSum += arr[i];
        auto it = sum.lower_bound(curSum - k);
        if (it != sum.end()) {
            ret = max(ret, curSum - *it);
        }
        sum.insert(curSum);
    }
    return ret;
}

void test_case_1() {
    vector<int> arr{3, 1, 4, 8, 2};
    assert(maxSumSeq(arr, 6) == 5);
}

void test_case_2() {
    vector<int> arr{3, 1, 4, 8, 2};
    assert(maxSumSeq(arr, 4) == 4);
}

void test_case_3() {
    vector<int> arr{3, 1, 4, 8, 2};
    assert(maxSumSeq(arr, 13) == 13);
}

void test_case_4() {
    vector<int> arr{3, 1, 4, 8, 2};
    assert(maxSumSeq(arr, 1) == 1);
}

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();

    return 0;
}
