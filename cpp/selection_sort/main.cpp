#include <array>
#include <algorithm>
#include <iostream>

using namespace std;

void selection_sort(array<int, 6> &arr) {
  int n = arr.size();
  for(int j = 0; j < n - 1; j++) {
    int smallest = j;
    for(int i = j + 1; i < n; i++) {
      if(arr[i] < arr[smallest]) {
        smallest = i;
      }
    }
    swap(arr[j], arr[smallest]);
  }
}

int main(void) { 
  std::array<int, 6> arr{5, 2, 4, 6, 1, 3};
  selection_sort(arr);

  for (int elem : arr) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  return 0; 
}
