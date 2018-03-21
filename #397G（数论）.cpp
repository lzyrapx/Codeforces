#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=500001;

int q_mod(ll res,ll n) 
{  
    ll ans=1;  
    while(n){  
        if(n&1) ans=(ans*res)%mod;     
        n>>=1;  
        res=(res*res)%mod;  
    }  
    return ans;  
}  
int m;
int calc(ll x)
{
	int ans =0 ;
	for (int i = 0; i< m; i++)
	{
		ans += (x >> i) & 1;
	}
	return ans;
}
int a[maxn];
const int maxx = 1e7;
pair <ll, ll> b[maxx], c[maxx];
int bc, cc;
ll ans[maxn];

int main()
{
	string s;
	int n;
	cin >> s;
	m = s.length();
	ll block = 0;
	for (int i = 0; i < m; i++)
	{
		block += ((ll)(s[i] - '0') << i);
	}
	

	cin >> n;
	ll mul = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		int y;
		cin >> y;
		mul = (mul * q_mod(a[i], y - 1)) % mod;
	}
	
	sort(a, a + n);
	
	int p = 0;
	bc = 1;
	b[0] = make_pair(0, 1);
	while ((p < n) && (a[p] < m))
	{
		cc = 0;
		int x = a[p++];
		
		for (int i = 0; i < x; i++)
		{
			ll cur = 0;
			for (int j = 0; j < m; j++)
			{
				if ((i + j) % x == 0) cur += (1ll << j);
			}
			if (cur & block) continue;
			for (int i = 0; i < bc; i++)
			{
				c[cc++] = make_pair(b[i].first | cur, b[i].second);
			}
		}
		
		sort(c, c + cc);
		
		int l, r;
		bc = 0;
		for (l = 0; l < cc; l = r)
		{
			b[bc] = c[l];
			r = l + 1;
			while ((r < cc) && (c[l].first == c[r].first))
			{
				b[bc].second += c[r++].second;
			}
			b[bc++].second %= mod;
		}
	}
	
	memset(ans, 0, sizeof(ans));
	
	int blc = calc(block);
	
	for (int i = 0; i < bc; i++)
	{
		int vl = m - blc - calc(b[i].first);
		ans[vl] = (ans[vl] + b[i].second) % mod;
	}
	
	for (int i = p; i < n; i++)
	{
		ll x=  a[i];
		for (int j = 0; j <= m; j++)
		{
			if (j != 0) 
				ans[j - 1] = (ans[j - 1] + ans[j] * j) % mod;
			ans[j] = (ans[j] * (x - blc - j)) % mod;
		}
	}
	return 0*printf("%I64d\n",ans[0]*mul % mod);
}
/*
1011
1
3 1000000000

411979884
*/
