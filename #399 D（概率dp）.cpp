#include<bits/stdc++.h>
using namespace std;
double dp[10005][1005];
//总共有k种物品，每天产生一种物品（等概率）。
//问至少需要几天才能保证收集齐K种物品的概率超过(p - 1e-7)/2000
int main()
{
	int k,q;
	cin>>k>>q;
	dp[0][0]=1.;
	for(int i=1;i<=10000;i++){
		for(int j=1;j<=k;j++)
		//dp[i][j] 表示前i天总共得到了j种物品
		dp[i][j]=(dp[i-1][j] * j + dp[i-1][j-1] * (k-j+1))/k;
	}
	int p;
	while(q--){
		cin>>p;
		int i=1;
		int ans=0;
		while(dp[i][k]*2000 + 1e-7 < p )
		{
			i++;
		}
		cout<<i<<endl;	
	}
	return 0;
}
/*
3 5
1
4
20
50
300

3
3
3
3
3
*/
