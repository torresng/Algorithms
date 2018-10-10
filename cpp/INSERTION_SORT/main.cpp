#include <iostream>
#include <array>

using namespace std;

array<int, 6> insertion_sort(array<int, 6> A) {
    int len = A.size();
    for(int j = 1; j <= len - 1; j++) {
        int key = A[j];
        // Insert A[j] into the sorted sequence A[1..j-1].
        int i = j - 1;
        while(i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            --i;
        }
        A[i + 1] = key;
    }

    return A;
}

int main() {
    array<int, 6> a { 5, 2, 4, 6, 1, 3 };
    a = insertion_sort(a);
    for(auto v : a) {
        cout << v << endl;
    }
    return 0;
}
