//#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
/*
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
*/
#define N 400000
int n,q; 
int ai[N], rem[N], red[N];
int ft, tl, ans;
int main()
{
	ft = 1; tl = 0;
	cin >> n >> q;
	for (int i = 1; i <= q; ++ i)
	{
		int tp, x;
		cin >> tp >> x;
		if (tp == 1)
		{
			ai[++ tl] = x;
			rem[x] ++;
			ans ++;
		}
		else if (tp == 2)
		{
			red[x] = tl;
			ans -= rem[x];
			rem[x] = 0;
		}
		else
		{
			while (ft <= x)
			{
				if (red[ai[ft]] < ft)
				{
					rem[ai[ft]] --;
					ans --;
				}
				ft ++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}