10. 快速幂
求 m^k mod p，时间复杂度 O(logk)。

```cpp
int qmi(int m, int k, int p)
{
    int res = 1, t = m;
    while (k)
    {
        if (k&1) res = res * t % p;
        t = t * t % p;
        k >>= 1;
    }
    return res;
}
```
