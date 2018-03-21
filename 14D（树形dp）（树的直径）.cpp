#include<bits/stdc++.h>
using namespace std;
const int N=234;
vector<int> Tree[N];
int ans;
//题意：
//给定一个无向图，含有一定的路。从中找出两个最长的路径（每条路径有一些相通路组成）。
//这两个路径不能经过公共的点，求什么时候两条路径的乘积最大。 
//
//题解：
//把一个图沿一条边割开，分成两个树，求这两个数中最长的路的乘积。
//这里需要分别求两个树的直径。
//因为题目数据不大，直接枚举边即可。(n^2) 
//DFS从当前点开始搜索，把枚举的那条边先当作删掉，DFS当前点存在的最大深度和次大深度。
//两个相加不断更新最值，便可得到其中一边树的直径。
//同样再DFS一次就可以得到另外一边树的直径。 
//最后相乘即可。

int n,deep;
bool Map[N][N];

int dfs(int son,int root)
{
    int s=0;
    int maxd1=0,maxd2=0;
    for(int i=1;i<=n;i++)
	{
        if(Map[son][i]==true && i!=root)
		{
			int tmp = dfs(i,son);
            s=max(tmp,s);
        //maxd1保存的是从son的最大深度 
		//maxd2是从son出发次大深度 
		//它们二者之和就是最长可扩展的路的长度，下面会用到 
            if(deep > maxd1)
			{
				maxd2=maxd1;
				
				maxd1=deep;
            }
            else 
			{
				maxd2=max(deep,maxd2);
			}
        }
    }
//    cout<<endl;
//    cout<<"son="<<son<<endl;
//    cout<<"1="<<maxd1<<endl;
//	cout<<"2="<<maxd2<<endl; 
//	cout<<endl;
    //二者之和就是最长可扩展的路的长度
    s = max(s, maxd1 + maxd2);
    deep = maxd1 + 1;
    return s;//返回树的直径
}

int main()
{
    int u,v;
    cin>>n;
    memset(Map,0,sizeof(Map));
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v;
        Map[u][v]=Map[v][u]=true;
    }
  	ans=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1;j<=n;j++)
        {
          	if(Map[i][j]==true)
         	{
               	int a=dfs(i,j);
//               	cout<<"----"<<endl;
               	int b=dfs(j,i);
               	ans=max(ans,a*b);
           	}
        }
	}
    cout<<ans<<endl;
    return 0;
}