#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5;
const int mod = 1e9+7;
const ll INF =2e15;
int a[maxn],b[maxn];
int vis[maxn];
int ans[maxn];
std::map<int, int> mp;

/*
题意：给你x%ci=bi（x未知）,是否能确定x%k的值（k已知）

——数学相关知识：
首先：我们要知道一些知识，对于k,假设有ci%k==0,那么一定能确定x%k的值，比如k=5和ci=20，知道x%20=y，那么ans=x%k=y%5;
介绍（互质版）中国剩余定理，假设已知m1,m2,mn，两两互质,且又知道x%m1,x%m2..x%mn分别等于多少
设M=m1*m2*m3..mn,那么x在模M的剩余系下只有唯一解（也就是知道了上面的模线性方程组，就可以求出x%M等于多少）

——此题解法
针对这个题呢，我们要确定x%k，只要保证知道上述的互质的模线性方程组就好
怎么样得到模线性方程组呢，直接把k唯一分解就好
即：k=p1^k1*p2^k2...*pr^kn，如果任意i，都有pi^ki的倍数出现在集合中（在模M的剩余系下）
(这一点如果不懂可以看上面，如果知道一个数倍数的取模，那么它肯定也知道)，那么k就能被猜出来。

分析：只要保证k能整除ci的最小公倍数即可
*/

ll lcm(ll a, ll b)
{
  return a / __gcd(a,b) * b;
}
int c[maxn];
int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  ll k;
  std::cin >> k;
  ll g = 1;
  for(int i=1;i<=n;i++) {
    //std::cin >> c[i];
    scanf("%d",&c[i]);
    g = lcm(g,c[i]);
    g = __gcd(g,k);
    if(g==k) {
      std::cout << "Yes" << '\n';
      return 0;
    }
  }
  std::cout << "No" << '\n';
  return 0;
}
