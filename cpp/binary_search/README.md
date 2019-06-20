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
