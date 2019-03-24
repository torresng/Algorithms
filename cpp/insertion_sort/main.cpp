#include <array>
#include <iostream>

void insert_sort(std::array<int, 6> &arr) {
  int j;
  for (j = 1; j < arr.size(); j++) {
    int key = arr[j];
    int i = j - 1;
    while (i >= 0 && arr[i] > key) {
      arr[i + 1] = arr[i];
      i = i - 1;
    }
    arr[i + 1] = key;
  }
}

int main(void) {
  std::array<int, 6> arr{5, 2, 4, 6, 1, 3};
  insert_sort(arr);

  for (int elem : arr) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  return 0;
}
