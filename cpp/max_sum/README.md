在數組中找出連續的和，其和為等於k或小於k的最大值

## 思路

用 curSum[j]表示位置之前所有數組元素之和，依次將 curSum 存入 set 中，如果 j 之前存在位置滿足

```
curSum[j] - curSum[i] <= k
```

表明以位置 j 結尾的序列有滿足條件不大於或等於 k 的，在 set 中二分查找 curSum[j] - k，查找到的位置即是以 j 結尾且相加和不大於或等於 k 的最大序列的開始位置，最後比較并更新最大序列和。如果不存在滿足 

```
curSum[j] - curSum[i] <= k 
```

的位置 i，表明以位置 j 結尾的所有序列相加和均大於 k。

因為

```
curSum - (curSum - k) = curSum - curSum + k = k
```

而且

```
curSum - (curSum - k + 1) = curSum - curSum + k - 1 = k - 1
```

所以算法用 lower_bound 方法找出等於或第一個大於(curSum - k)的值

```cpp
// Returns an iterator pointing to the first element in the container which is not 
// considered to go before val (i.e., either it is equivalent or goes after).
std::set::lower_bound
```
