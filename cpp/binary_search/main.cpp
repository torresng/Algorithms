#include <array>
#include <cassert>
#include <iostream>

using namespace std;

int iterative_binary_search(array<int, 6> &arr, int v, int low, int high) {
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

int recursive_binary_search(array<int, 6> &arr, int v, int low, int high) {
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
  array<int, 6> arr{1, 2, 3, 4, 5, 6};
  assert(iterative_binary_search(arr, 3, 0, 5) == 2);
  assert(iterative_binary_search(arr, 6, 0, 5) == 5);
  assert(iterative_binary_search(arr, 1, 0, 5) == 0);
  assert(iterative_binary_search(arr, 8, 0, 5) == -1);
}

void test_case_2() {
  array<int, 6> arr{1, 2, 3, 4, 5, 6};
  assert(recursive_binary_search(arr, 3, 0, 5) == 2);
  assert(recursive_binary_search(arr, 6, 0, 5) == 5);
  assert(recursive_binary_search(arr, 1, 0, 5) == 0);
  assert(recursive_binary_search(arr, 8, 0, 5) == -1);
}

int main(void) {
  test_case_1();
  test_case_2();

  return 0;
}
