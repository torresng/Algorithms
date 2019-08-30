# 深度优先遍历
		int dfs(int u)
		{
			st[u] = true; // st[u] 表示点u已经被遍历过
	
			for (int i = h[u]; i != -1; i = ne[i])
			{
				int j = e[i];
				if (!st[j]) dfs(j);
			}
		}