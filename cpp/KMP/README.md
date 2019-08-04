# KMP

```
求Next数组：
// s[]是模式串，p[]是模板串, m是s的长度，n是p的长度
for (int i = 2, j = 0; i <= n; i ++ )
{
	while (j && p[i] != p[j + 1]) j = ne[j];
	if (p[i] == p[j + 1]) j ++ ;
	ne[i] = j;
}

// 匹配
for (int i = 1, j = 0; i <= m; i ++ )
{
	while (j && s[i] != p[j + 1]) j = ne[j];
	if (s[i] == p[j + 1]) j ++ ;
	if (j == n)
	{
		j = ne[j];
		// 匹配成功后的逻辑
	}
}
```

