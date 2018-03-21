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
const int N = 101010; 
template <class T1, class T2>inline void getmax(T1 &a, T2 b) { if (b>a)a = b; }  
template <class T1, class T2>inline void getmin(T1 &a, T2 b) { if (b<a)a = b; }
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
map<int,int>mp[33];

void add(int x,int k)
{
    int sum = 0;
    for(int i=29;i>=0;--i)
    {
        if((x>>i) & 1)
            sum+= 1<<i;
        mp[29-i][sum] += k;
    }
}

int query(int x)
{
    int ans = 0;
    for(int i= 0;i<30; i++)
    {
        int r =29 - i;
        if((x>>r) & 1)
        {
            if(!mp[i][ans])
                ans += 1<<r;
        }
        else {
            if(mp[i][ans + (1<<r)])
                ans += 1<<r;
        }
    }
    return ans;
}
int main() 
{
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    int q;
    q=read();
    while(q--)
    {
        char c;
        int x;
        scanf(" %c %d",&c,&x);
        if(c=='+') add(x,1);
        else if(c=='-') add(x,-1);
        else printf("%d\n",max(x,query(x)^x));
    }
    return 0;
   
}
