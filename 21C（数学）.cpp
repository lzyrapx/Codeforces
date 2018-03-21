#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//给一串长N的数列，把它们划成3段使每段和相等（数列的顺序不能打乱）
//问有几种分法？ 
int main()
{
	ll n; ll sum = 0; 
	cin>>n;
	vector<ll>a(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum = sum+a[i]; 
	}
	if(sum%3!=0){
		puts("0");
		exit(0);
	}
	ll ans = 0;
	ll tmp = 0;
	sum /= 3;
	ll k = 0;
	for(int i=1;i<n;i++)
	{
		 tmp = tmp + a[i];
		 if(tmp == 2*sum) ans = ans + k;
		 if(tmp == sum )k++; 
	}
	cout<<ans<<endl;
	return 0;
}