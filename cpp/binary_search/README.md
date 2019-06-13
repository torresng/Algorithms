# 二分模板


## 版本1

當我們將區間[l, r]划分成[l, mid]和[mid + 1, r]時，
其更新操作是r = mid或者l = mid + 1，計算mid時不需要加1。

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


## 版本2

當我們將區間[l, r]划分成[l, mid - 1]和[mid, r]時，
其更新操作是r = mid - 1或者l = mid，此時為了防止死循環，計算mid時需要加1。

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
