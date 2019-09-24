1. 树与图的存储
	树是一种特殊的图，与图的存储方式相同。
	对于无向图中的边ab，存储两条有向边a->b, b->a。
	因此我们可以只考虑有向图的存储。
	
	(1) 邻接矩阵：g[a][b] 存储边a->b
	
	(2) 邻接表：
		
		// 对于每个点k，开一个单链表，存储k所有可以走到的点。h[k]存储这个单链表的头结点
		int h[N], e[N], ne[N], idx;
		
		// 添加一条边a->b
		void add(int a, int b)
		{
			e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
		}

2. 树与图的遍历
	(1) 深度优先遍历
	
		int dfs(int u)
		{
		st[u] = true; // st[u] 表示点u已经被遍历过
			for (int i = h[u]; i != -1; i = ne[i])
			{
				int j = e[i];
				if (!st[j]) dfs(j);
			}
		}
	
	(2) 宽度优先遍历
	
		queue<int> q;
		st[1] = true; // 表示1号点已经被遍历过
		q.push(1);
	
		while (q.size())
		{
			int t = q.front();
			q.pop();
	
			for (int i = h[t]; i != -1; i = ne[i])
			{
				int j = e[i];
				if (!s[j])
				{
					st[j] = true; // 表示点j已经被遍历过
					q.push(j);
				}
			}
		}