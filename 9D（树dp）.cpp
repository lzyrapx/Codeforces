#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[40][40];
//n个节点高度小于等于n的树的种数－n个节点高度小于等于h-1的种数
int main()
{
	int n,h;
	cin>>n>>h;
	for(int i=1;i<=n;i++)//高度 
	{  
		dp[0][i-1] = 1;
		for(int j=1;j<=n;j++)//拿n个节点
		{
			for(int k=0;k<j;k++)//左子树 
			{
				dp[j][i] += dp[k][i-1] * dp[j-k-1][i-1];
			}
		}		
	}
	cout<<dp[n][n]-dp[n][h-1]<<endl;
	return 0;
}