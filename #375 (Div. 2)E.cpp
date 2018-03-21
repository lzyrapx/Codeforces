#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int n;
int mat[210][210];
int deg[210];
int p[210];

vector<pair<int, int>> ans;

void dfs(int u)
{
	for (; p[u] <= n; ++p[u])
	{
		int v = p[u];
		if (mat[u][v])
		{
			mat[u][v] = mat[v][u] = 0;
			ans.emplace_back(u, v);
			--deg[u], --deg[v];
			dfs(v);
			break;
		}
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int m;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; ++i)
			p[i] = 1;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				mat[i][j] = 0;
		while (m--)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			mat[u][v] = mat[v][u] = 1;
			++deg[u], ++deg[v];
		}
		ans.clear();
		int odd = 0;
		for (int i = 1; i <= n; ++i)
			odd += deg[i] & 1;
		for (int i = 1; i <= n; ++i)
			if (deg[i] & 1)
				dfs(i);
		for (int i = 1; i <= n; ++i)
			if (deg[i])
				dfs(i);
		printf("%d\n", n - odd);
		for (auto &p : ans)
			printf("%d %d\n", p.first, p.second);
	}
	return 0;
}