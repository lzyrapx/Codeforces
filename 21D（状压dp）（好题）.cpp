#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int w[34][34];
int d[32768];
int dp[32768];
int ans = 0;
/*
考虑度数为偶数的点不需要被考虑，只需要考虑度数为奇数的情况。
首先每条边必须要访问一次，所以所有边权加起来就是答案的初值。　
然后度数为奇数的点就需要访问之前已经走过的边。
我们考虑两个度数为奇数的点可以组合一下，变成度数为偶数的点，
相当于是在这两个点之间新连了一条边，我们可以floyd预处理一下两点之间的最短路。
然后状压，状态表示当前哪些结点的度数为奇数，然后枚举每次连哪两条边就可以了。
*/ 
int main()
{
	int n,m;
	cin>>n>>m;
	int x,y,z;
	if(m==0)return 0*puts("0");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		{
			w[i][j] = (1<<29);
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		d[x]++;
		d[y]++;
		ans+=z;
		if(w[x][y]>z)//重边 
		{
			w[x][y] = z;
			w[y][x] = z;
		}
	}
	//考虑两个度数为奇数的点可以组合一下，变成度数为偶数的点，
	//相当于是在这两个点之间新连了一条边，我们可以floyd预处理一下两点之间的最短路 
	for(int k=1;k<=n;k++)//floyd 
	{
		for(int i=1;i<=n;i++)
		{
			if(i!=k)
			{
				for(int j=1;j<=n;j++)
				{
					if(i!=j && j!=k)
					{
						w[i][j] = min(w[i][j],w[i][k]+w[k][j]);
					}
				}
			}
		}
	}
	for(int i=2;i<=n;i++)
	{
		if(d[i] != 0 && w[1][i] == (1<<29))
		{
			return 0*puts("-1");
		}
	}
	int end = 0;
	for(int i=1;i<=n;i++)
	{
		if(d[i]&1)//度数是奇数 
		{
			end |= (1<<(i-1)); //状态表示当前哪些结点的度数为奇数 
			//cout<<"end="<<end<<endl;  
		}
	}
	for(int i=0;i<=end;i++)
	{
		dp[i] =  (1<<29);
		dp[end] = 0;
	}
	int now = 0;
	//枚举每次连哪两条边就可以了
	for(int i=end;i>=1;--i)
	{
		if(dp[i]==(1<<29)) continue;
		for(int j=1;j<=n;j++)
		{
			if(((1<<(j-1)) & i) == 0) continue;
			for(int k=1;k<=n;k++)
			{
				if(((1<<(k-1)) & i ) == 0) continue;
				now = i ^ (1<<(k-1)) ^ (1<<(j-1));
			//	cout<<"now="<<now<<endl;
				dp[now] = min(dp[now],dp[i] + w[j][k]); //取或不取 j 和 k 两条边 
			}
		}
	}
//	for(int i = 0;i<=end;i++){
//		cout<<dp[i]<<endl;
//	}
	ans = ans + dp[0];
	cout<<ans<<endl;
	return 0;
}