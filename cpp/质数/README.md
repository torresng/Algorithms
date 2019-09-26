1. 试除法判定质数

```cpp
bool is_prime(int x)
{
  if (x < 2) return false;
  for (int i = 2; i <= x / i; i ++ )
      if (x % i == 0)
          return false;
  return true;
}
```

2. 试除法分解质因数

```cpp
void divide(int x)
{
  for (int i = 2; i <= x / i; i ++ )
      if (x % i == 0)
      {
          int s = 0;
          while (x % i == 0) x /= i, s ++ ;
          cout << i << ' ' << s << endl;
      }
  if (x > 1) cout << x << ' ' << 1 << endl;
  cout << endl;
}
```

3. 朴素筛法求素数
	
```cpp
int primes[N], cnt;		// primes[]存储所有素数
bool st[N];			// st[x]存储x是否被筛掉

void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (st[i]) continue;
        primes[cnt ++ ] = i;
        for (int j = i; j <= n; j += i)
            st[j] = true;
    }
}
```
