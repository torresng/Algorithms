# 二分模板

## 模板 1

```cpp
while(left <= right) {
    int mid = (left + right) / 2;
    if(arr[mid] ? key) {
        //... right = mid - 1;
    } else {
        //... left = mid + 1;
    }
}
return xxx;
```

## 模板 2

# AcWing

### 版本 1

當我們將區間[l, r]划分成[l, mid]和[mid + 1, r]時，
其更新操作是 r = mid 或者 l = mid + 1，計算 mid 時不需要加 1。

```cpp
int bSearch_1(int l, int r) {
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
```

### 版本 2

當我們將區間[l, r]划分成[l, mid - 1]和[mid, r]時，
其更新操作是 r = mid - 1 或者 l = mid，此時為了防止死循環，計算 mid 時需要加 1。

```cpp
int bSearch_2(int l, int r) {
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}
```

```cpp
// 整数二分算法模板

bool check(int x) {/* ... */} // 检查x是否满足某种性质

// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;    // check()判断mid是否满足性质
        else l = mid + 1;
    }
    return l;
}
// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

// 浮点数二分算法模板

bool check(double x) {/* ... */} // 检查x是否满足某种性质

double bsearch_3(double l, double r)
{
    const double eps = 1e-6;   // eps 表示精度，取决于题目对精度的要求
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    return l;
}
```
