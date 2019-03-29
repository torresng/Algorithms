#include <array>
#include <iostream>

template <class T, int N> void insert_sort(std::array<T, N> &arr) {
  int j;
  for (j = 1; j < arr.size(); j++) {
    T key = arr[j];
    int i = j - 1;
    while (i >= 0 && arr[i] > key) {
      arr[i + 1] = arr[i];
      i = i - 1;
    }
    arr[i + 1] = key;
  }
}

void test_case_1() {
  std::array<int, 6> arr{5, 2, 4, 6, 1, 3};
  insert_sort<int, 6>(arr);
  std::array<int, 6> result{1, 2, 3, 4, 5, 6};

  for(int i = 0; i < arr.size(); i++) {
  assert(arr[i] == result[i]);
  }
}

int main(void) {
  test_case_1();

  return 0;
}
