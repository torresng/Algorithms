#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

void merge(vector<PII> &segs) {
    if (segs.empty()) {
        return;
    }

    sort(segs.begin(), segs.end());

    vector<PII> res;
    int st = -2e9, ed = -2e9;
    for (auto seg : segs) {
        if (ed < seg.first) {
            if (st != -2e9) {
                res.push_back({st, ed});
            }
            st = seg.first, ed = seg.second;
        } else {
            ed = max(ed, seg.second);
        }
    }

    res.push_back({st, ed});
    segs = res;
}

int main() {
    int n;
    cin >> n;

    vector<PII> segs;
    for (int i = 0; i < n; ++i) {
        int st, ed;
        cin >> st >> ed;
        segs.push_back({st, ed});
    }

    merge(segs);

    cout << segs.size() << endl;

    return 0;
}
