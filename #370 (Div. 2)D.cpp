#pragma comment(linker, "/STACK:102400000,102400000")
//#include<bits/stdc++.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <bitset>
#include <iomanip>
#include <list>
#include <stack>
#include <utility> 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
const double eps = 1e-8;  
const int INF = 1e9+7; 
const ll inf =(1LL<<62) ;
const int MOD = 1e9 + 7;  
const ll mod = 1e9+7;
const int N =200010; 
const int M=100010;
const int maxn=1001;
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)
#define pi acos(-1.0)
#define in freopen("in.txt","r",stdin) 
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--)  
#define lson x << 1, l, mid  
#define rson x << 1 | 1, mid + 1, r  
const int lowbit(int x) { return x&-x; }
//const int lowbit(int x) { return ((x)&((x)^((x)-1))); } 
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
ll dp[N], sums[N];
ll a, b, k, t;
int main() {
	cin >> a >> b >> k >> t;
	dp[100001] = 1;
	for (int i = 1; i < N; i++) {
		sums[i] = sums[i - 1] + dp[i];
	}
	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < N; j++)
		{
			dp[j] = ( (sums[min(j + k, 200001LL)] - sums[max(j - k - 1, 0LL)]) % mod + mod) % mod;
		}
		for (int j = 1; j < N; j++)
		{
			sums[j] = (sums[j - 1] + dp[j]) % mod;
		}
	}
	ll ans = 0;
	for (int j = 0; j < N; j++)
	{
		ans = ((ans + dp[j] * (sums[ max(min(a + j - b - 1, 200001LL), 0LL)])) % mod + mod) % mod;
	}
	cout << ans;
	return 0;
} 


-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
int dp[210][400010];
const int mod=1e9+7;
int gao(int x,int y)
{
	return y<0 ? 0 : dp[x][y];
}
int main()
{
	int a,b,k,t;
	int ans;
	scanf("%d%d%d%d",&a,&b,&k,&t);
	k <<= 1;
	a = t*k-a+b;
	t <<= 1;
	ans = t*k;
	if(a>ans){
		cout<<0<<endl;
		return 0;
	}
	for(int i=0;i<=ans;i++) dp[0][i]=1;
	
	for(int i=1;i<=t;i++)
	for(int j=0;j<=ans;j++)
	{
		dp[i][j]=((long long)gao(i,j-1) + gao(i-1,j) - gao(i-1,j-k-1))%mod;
	}
	ans = ( gao(t,ans) - gao(t,a) )%mod;
	if(ans<0) ans+=mod;
	printf("%d\n",ans);
	return 0;
}