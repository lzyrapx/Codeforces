#include<bits/stdc++.h>
using namespace std;
const int maxn = 2005;
int n,m;
int a[maxn];
int cnt[maxn],vis[maxn];
int ans2=0;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int ans1=n/m;
	int p=n%m;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>m)continue;
		if(cnt[a[i]]>=ans1)continue;
		cnt[a[i]]++;
		vis[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		int Ans1=1e9,Ans2=1e9;
		for(int j=1;j<=m;j++)
		{
			if(cnt[j]<Ans2)
				Ans2=cnt[j],Ans1=j;
		}
		if(Ans2==ans1)continue;
		ans2++;
		cnt[Ans1]++,a[i]=Ans1;
	}
	cout<<ans1<<" "<<ans2<<endl;
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}