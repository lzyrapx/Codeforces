#pragma comment(linker, "/STACK:102400000,102400000")
//#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
#include<set>
#include <utility>
#include<stack>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)  
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--)  
#define lson x << 1, l, mid  
#define rson x << 1 | 1, mid + 1, r  
const int lowbit(int x) { return x&-x; }  
const double eps = 1e-8;  
const int INF = 1e9+7; 
const ll inf =(1LL<<62) ;
const int MOD = 1e9 + 7;  
const ll mod = (1LL<<32);
const int N = 1010;
const int M=2000010; 
template <class T1, class T2>inline void getmax(T1 &a, T2 b) {if(b>a)a = b;}  
template <class T1, class T2>inline void getmin(T1 &a, T2 b) {if(b<a)a = b;}
int read()
{
	int v = 0, f = 1;
	char c =getchar();
	while( c < 48 || 57 < c ){
		if(c=='-') f = -1;
		c = getchar();
	}
	while(48 <= c && c <= 57) 
		v = v*10+c-48, c = getchar();
	return v*f;
}

int a[N][N];
int r[M],d[M];
int main() 
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    int n,m;
    int q,h,w,lx,ly,rx,ry;
    n=read();m=read();q=read();
    for(int i=1; i<=n; i++)
    	for(int j=1; j<=m; j++)
    	{
    		a[i][j]=read();
		}
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=m;j++)
			{
				r[i*(m+1)+j] = i*(m+1)+(j+1);
				d[i*(m+1)+j] = (i+1)*(m+1)+j;		
			}
		}
		while(q--)
		{
			scanf("%d%d%d%d%d%d",&lx,&ly,&rx,&ry,&h,&w);
			int up = 0;
			int down = 0;
			for(int i=1;i<lx;i++) up=d[up];
			for(int i=1;i<ly;i++) up=r[up];
			for(int i=1;i<rx;i++) down=d[down];
			for(int i=1;i<ry;i++) down=r[down];
			int pp=up;
			int dd=down;
			for(int i=0;i<h;i++){
				pp=d[pp]; 
				dd=d[dd];
				swap(r[pp],r[dd]);
			}
			for(int i=0;i<w;i++){
				pp=r[pp];
				dd=r[dd];
				swap(d[pp],d[dd]);
			}
			
			 pp=up;
			 dd=down;
			 
			 for(int i=0;i<w;i++){
				pp=r[pp];
				dd=r[dd];
				swap(d[pp],d[dd]);
			}	
			 for(int i=0;i<h;i++){
				pp=d[pp];
				dd=d[dd];
				swap(r[pp],r[dd]);
			}
			
		}
		int up=0,down;
		for(int i=1;i<=n;i++){
		   	up=down=d[up];
		   	for(int j=1;j<=m;j++)
		   	{
		   		down=r[down];
		   		printf("%d ",a[down/(m+1)][down%(m+1)]);
			   }
			   puts("");
		   }
	return 0; 
}