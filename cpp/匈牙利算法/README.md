# 匈牙利算法

```
int n;		// n表示点数
int h[N], e[M], ne[M], idx;		// 邻接表存储所有边
int match[N];		// 存储每个点当前匹配的点
bool st[N];		// 表示每个点是否已经被遍历过

bool find(int x)
{
	for (int i = h[x]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (!st[j])
		{
			st[j] = true;
			if (match[j] == 0 || find(match[j]))
			{
				match[j] = x;
				return true;
			}
		}
	}
	
	return false;
}

// 求最大匹配数
int res = 0;
for (int i = 1; i <= n; i ++ )
{
	memset(st, false, sizeof st);
	if (find(i)) res ++ ;
}
```
