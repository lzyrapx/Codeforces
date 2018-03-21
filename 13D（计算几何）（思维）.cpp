#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=567;
int a[N][N];
ll rx[N],ry[N],bx[N],by[N];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	   cin>>rx[i]>>ry[i];//red
	for(int i=1;i<=m;++i)
	   cin>>bx[i]>>by[i];//blue
	   
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(rx[i]<rx[j])
			{
				//Ax+By+C=0
				ll A=ry[j]-ry[i];
				ll B=rx[i]-rx[j];
				ll C=-A*rx[i]-B*ry[i];
				for(int k=1;k<=m;++k)
				{
					if(rx[i]<=bx[k] && bx[k]<rx[j] && A*bx[k]+B*by[k]+C>0)//将蓝点左边代入直线方程 
					{
						a[i][j]++;//i-j边的上方有一个蓝点 
					}
				}	
				a[j][i]=-a[i][j];
			}
		}
	}
	
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			for(int k=j+1;k<=n;++k)
			{
				if(a[i][j]+a[j][k]+a[k][i]==0)//i,j,k三条边围成的三角形中没有蓝点的个数 
				{
					ans++;
				}
			}	
		}
	}
	cout<<ans<<endl;
	return 0;
}