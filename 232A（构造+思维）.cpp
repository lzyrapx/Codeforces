#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int g[123][123];
int main()
{
	int k;
	cin>>k;//要求的三元环个数 
	for(int i=0;i<90;i++)//依次增加顶点 
	{
		int sum = 0;//三元环个数 
		for(int j = 0; j < i && sum <= k;j++)
		{
			k-=sum;
			sum++;
			g[i][j] = g[j][i] = 1;
		}
	 }
	cout<<90<<endl;
	for(int i=0;i<90;i++)
	{
		for(int j=0;j<90;j++)
		{
			int ans = g[i][j] ? 1:0;
			cout<<ans;
		}
		cout<<endl;
	}
	return 0;
}