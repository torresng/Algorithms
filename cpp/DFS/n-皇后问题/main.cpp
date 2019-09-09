#include <iostream>

using namespace std;

// 第一種方法
const int N = 20;

int n;
char g[N][N];
bool col[N], dg[N], udg[N];

void dfs(int u) {
    if (n == u) {
        for (int i = 0; i < n; i++) {
            puts(g[i]);
        }
        puts("");
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!col[i] && !dg[u + i] && !udg[u - i + n]) {
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[u - i + n] = true;
            dfs(u + 1);
            col[i] = dg[u + i] = udg[u - i + n] = false;
            g[u][i] = '.';
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = '.';
        }
    }

    dfs(0);

    return 0;
}

// 第二種方法
/*
 *const int N = 20;
 *
 *int n;
 *char g[N][N];
 *bool row[N], col[N], dg[N], ndg[N];
 *
 *void dfs(int x, int y, int s) {
 *    if (y == n) {
 *        y = 0;
 *        x++;
 *    }
 *
 *    if (x == n) {
 *        if (s == n) {
 *            for (int i = 0; i < n; i++) {
 *                puts(g[i]);
 *            }
 *            puts("");
 *        }
 *        return;
 *    }
 *
 *    // 不放皇後
 *    dfs(x, y + 1, s);
 *
 *    // 放皇後
 *    if (!row[x] && !col[y] && !dg[y + x] && !ndg[y - x + n]) {
 *        g[x][y] = 'Q';
 *        row[x] = col[y] = dg[y + x] = ndg[y - x + n] = true;
 *        dfs(x, y + 1, s + 1);
 *        row[x] = col[y] = dg[y + x] = ndg[y - x + n] = false;
 *        g[x][y] = '.';
 *    }
 *}
 *
 *int main() {
 *    cin >> n;
 *    for (int i = 0; i < n; i++) {
 *        for (int j = 0; j < n; j++) {
 *            g[i][j] = '.';
 *        }
 *    }
 *
 *    dfs(0, 0, 0);
 *
 *    return 0;
 *}
 */
