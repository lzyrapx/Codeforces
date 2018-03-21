#include<bits/stdc++.h>
using namespace std;
const int maxn = 55;
int n,m,k;
string s[maxn];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int vis[maxn][maxn];
int sp[maxn*maxn],cnt,area,flag;
void dfs(int x,int y)
{
	area++;
	vis[x][y]=1;
	if(x==0||x==n-1||y==0||y==m-1)flag=1;
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx<0||nx>=n)continue;
		if(ny<0||ny>=m)continue;
		if(s[nx][ny]=='*')continue;
		if(vis[nx][ny])continue;
		dfs(nx,ny);
	}
}
struct node
{
	int a,b,c;
}t[5000];

bool cmp(node a,node b)
{
	return a.a<b.a;
}
void dfs2(int x,int y)
{
	s[x][y]='*';
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx<0||nx>=n)continue;
		if(ny<0||ny>=m)continue;
		if(s[nx][ny]=='*')continue;
		dfs2(nx,ny);
	}	
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!vis[i][j]&&s[i][j]=='.')
			{
				area=0;
				flag=0;
				dfs(i,j);
				if(flag==1)continue;
				t[cnt].a=area,t[cnt].b=i,t[cnt].c=j;
				cnt++;
			}
		}
	}	
	sort(t,t+cnt,cmp);
	int aaans = 0;
	for(int i=0;i<cnt-k;i++)
	{
		aaans+=t[i].a;
		dfs2(t[i].b,t[i].c);
	}
	cout<<aaans<<endl;
	for(int i=0;i<n;i++)
		cout<<s[i]<<endl;
}