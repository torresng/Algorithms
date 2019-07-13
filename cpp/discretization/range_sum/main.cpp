#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 300010;

vector<int> alls; // 存儲所需的下標
vector<PII> adds, querys;

int a[N], s[N];

int find(int x) {
    int n = alls.size();
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (alls[mid] >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    // 返回從1,2,3,...,n的下標，方便之後計算前綴和
    return l + 1;
}

vector<int>::iterator unique(vector<int> &arr) {
    int j = 0;
    for (unsigned i = 0; i < arr.size(); ++i) {
        if (!i || arr[i - 1] != arr[i]) {
            arr[j++] = arr[i];
        }
    }
    return arr.begin() + j;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int x, c;
        cin >> x >> c;
        adds.push_back({x, c});
        alls.push_back(x);
    }

    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        querys.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }

    // 離散化
    // 去重大
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls), alls.end());

    // 將要加的值加到離散化後的位置
    for (PII add : adds) {
        int x = find(add.first);
        a[x] += add.second;
    }

    // 計算前綴和
    for (unsigned i = 1; i <= alls.size(); ++i) {
        s[i] = s[i - 1] + a[i];
    }

    // 處理詢問
    for (PII query : querys) {
        int l = find(query.first), r = find(query.second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}
