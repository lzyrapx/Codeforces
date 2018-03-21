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
#include<stack>
#include <utility> 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)
#define in freopen("in.txt","r",stdin) 
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--)  
#define lson  l , mid , rt << 1  
#define rson  mid + 1 , r , rt << 1 | 1  
const int lowbit(int x) { return x&-x; }  
const double eps = 1e-8;  
const int INF = 1e9+7; 
const ll inf =(1LL<<62) ;
const int MOD = 1e9+7;  
const ll mod = (1LL<<32);
const int N =2e5+7; 
const int M=100010;
const ll MAX=1e18;
//const int maxn=1001; 
template <class T1, class T2>inline void getmax(T1 &a, T2 b) {if (b>a)a = b;}  
template <class T1, class T2>inline void getmin(T1 &a, T2 b) {if (b<a)a = b;}
int read(){
int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
int a[N],r[N],t[N],b[N];
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	int op,x; int cnt=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i],b[i]=a[i];
	for(int i=0;i<m;i++){
		cin>>op>>x;
		while(cnt > 0 && x > r[cnt-1]) --cnt;
		t[cnt] = op, r[cnt] = x ;
		cnt++;	
	}
	//cout<<"cnt="<<cnt<<endl;
	//for(int i=0;i<m;i++) cout<<r[i]<<endl;
	r[cnt] = 0;
	sort(b,b+r[0]);
	int b_right=r[0]-1;
	int b_left=0;
	for(int i=1;i<=cnt;i++)
	{
		 for(int j=r[i-1] -1; j>=r[i];--j)
		 {
		 	if(t[i-1] == 1) a[j]= b[b_right--]; //递增 
		 	else a[j]=b[b_left++]; //递减 
		 }
	}
	for(int i=0;i<n;i++)cout<<a[i]<<" "; 
	return 0;
}