#include <array>
#include <cassert>
#include <iostream>

template <class T, int N>
int iterative_binary_search(std::array<T, N> &arr, int v, int low, int high) {
  while (low <= high) {
    int mid = (low + high) / 2;
    if (v == arr[mid]) {
      return mid;
    } else if (v > arr[mid]) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

template <class T, int N>
int recursive_binary_search(std::array<T, N> &arr, int v, int low, int high) {
  if (low > high) {
    return -1;
  }
  int mid = (low + high) / 2;
  if (v == arr[mid]) {
    return mid;
  } else if (v > arr[mid]) {
    return recursive_binary_search(arr, v, mid + 1, high);
  } else {
    return recursive_binary_search(arr, v, low, mid - 1);
  }
}

void test_case_1() {
  std::array<int, 6> arr{1, 2, 3, 4, 5, 6};
  int result;

  result = iterative_binary_search<int, 6>(arr, 3, 0, 5);
  assert(result == 2);

  result = iterative_binary_search<int, 6>(arr, 6, 0, 5);
  assert(result == 5);

  result = iterative_binary_search<int, 6>(arr, 1, 0, 5);
  assert(result == 0);

  result = iterative_binary_search<int, 6>(arr, 8, 0, 5);
  assert(result == -1);
}

int main(void) {
  test_case_1();

  return 0;
}
