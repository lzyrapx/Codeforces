#include<bits/stdc++.h>
using namespace std;
const int mod = 9973;
typedef long long ll;
const int N = 345;
int n,m;
ll link[1 << 20][20], circle[1 << 20];
bool vis[20][20];

//求一个图中（节点个数小于20）长度大于等于三的哈密顿路径数目。
//dp[i][j]表示状态为i时，以j结尾的路径条数。
//如果下一个点能回到已经走过的一个点中，那么就是一个回路了
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		u--;v--;
		vis[u][v]=1;
		vis[v][u]=1;
	}
	//初始化 
	for(int i=0;i<n;i++)
	{
		link[1<<i][i] = 1;
	}
	int limit = 1<<n;
	ll sum = 0;
	for(int i=1;i<limit;i++)//枚举状态 
	{
		int beg = -1;
		for(int j=0;j<n;j++)//枚举终点 
		{
			if((i>>j)& 1)
			{
				if(beg==-1){
					beg = j;
				}
				for(int k=beg+1;k<n;k++)//路的枚举 
				{
					if(!((i>>k)& 1))
					{
						int target = i + (1<<k);
						if(vis[j][k])
						{
							link[target][k] += link[i][j];
						}
						if(vis[j][k] && vis[beg][k])
						{
							circle[target] += link[i][j];
						}
						
					}
				}
			}
		}
		//cout<<"i="<<i<<" "<<circle[i]<<endl;
		if(__builtin_popcount(i) >= 3)//长度大于等于3的哈密顿回路 
		{
			//cout<<"i="<<i<<endl;
			sum += (circle[i] / 2 );//每个环会算两遍，最后要除以2 
		}
		
	}
	cout<<sum<<endl;
	return 0;	
} 
/*
4 6
1 2
1 3
1 4
2 3
2 4
3 4

7
*/