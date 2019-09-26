#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1000010;

int primes[N], cnt;
bool st[N];

// 埃氏篩法 O(nloglogn)
/*
void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            for (int j = i; j <= n; j += i) {
                st[j] = true;
            }
        }
    }
}
*/

// 線性篩法  O(n)
void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    get_primes(n);

    cout << cnt << endl;

    return 0;
}
