#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
ll N, ans = 1e18;
//p1^a1*p2^a2*.....pn^an
//约数个数就是(a1+1)*(a2+1)*....*(an+1) 
void dfs(int i, ll x, ll n)// i 为素数数组p的下标, x 为p_n, n 为约数个数 
{
	if (n > N) return;
	if (n == N && x < ans) ans = x;
	for (int j = 1; j <= 60; j++)
	{
		if (ans <= x*p[i]) return;
		dfs(i + 1, x *= p[i], n * (j + 1));//j就是a_j,因为2^60 > 1e18，所以枚举到60即可 
	}
}
int main()
{
	cin >> N; //n个约数 
	dfs(0, 1, 1);
	cout << ans << endl;
	return 0;
}