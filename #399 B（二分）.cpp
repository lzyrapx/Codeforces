
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans;
void solve(ll a,ll b,ll l, ll r, ll d)
{
	if(a > b || l > r) return;
	else{
		ll mid=(a+b)/2;
		if(r < mid)solve(a,mid-1,l,r,d/2);
		else if(mid < l)solve(mid+1,b,l,r,d/2);
		else{
			ans += d%2;
			solve(a,mid-1,l,mid-1,d/2);
			solve(mid+1,b,mid+1,r,d/2);
		}
	}
}
int main()
{
	ll n,l,r,sum=1;
	cin>>n>>l>>r;
	ll t=n;
	while(t>=2)
	{
		t/=2;
		sum=sum*2+1;
	}
	solve(1,sum,l,r,n);
	cout<<ans<<endl;
	return 0;
}