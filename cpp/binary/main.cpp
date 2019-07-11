#include <iostream>

using namespace std;

int lowbin(int x) { return x & -x; }

int main(void) {
    int n;
    cin >> n;

    while (n--) {
        int x;
        cin >> x;

        int res = 0;
        while (x) {
            x -= lowbin(x);
            ++res;
        }

        cout << res << ' ';
    }
    return 0;
}
