#include <algorithm>
#include <array>
#include <iostream>

using namespace std;

template <typename T, int N> void selection_sort(array<T, N> &arr) {
  int n = arr.size();
  for (int j = 0; j < n - 1; j++) {
    int smallest = j;
    for (int i = j + 1; i < n; i++) {
      if (arr[i] < arr[smallest]) {
        smallest = i;
      }
    }
    swap(arr[j], arr[smallest]);
  }
}

void test_case_1() {
  std::array<int, 6> arr{5, 2, 4, 6, 1, 3};
  selection_sort<int, 6>(arr);
  std::array<int, 6> result{1, 2, 3, 4, 5, 6};

  for (int i = 0; i < arr.size(); i++) {
    assert(arr[i] == result[i]);
  }
}

int main(void) {
  test_case_1();

  return 0;
}
