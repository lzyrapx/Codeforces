#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5;
const int mod = 1e9+7;
const ll INF =2e15;

ll power[maxn],cnt[maxn];
ll dp[maxn];
/*
题意：
gcd(a_1,a_2,a_3,....,a_k)>1
求\sum_ (k*gcd)，k为子集内元素个数

分析：对于固定的gcd，k是不固定，我们只要求出所有的满足gcd的贡献
利用组合数：子集大小 * (子集选择方案数)=
1*C(n,1)+2*C(n,2)+3*C(n,3)+....+n*C(n,n) = n * 2^(n-1)，n即为子集中含因子i的个数

*/
//cnt[i]表示 a_k 中能整除 i 的个数 (a_k / i),即 a_k中含因子i的个数
// dp[i]表示 gcd为 i 的全部集合元素个数

int main(int argc, char const *argv[]) {
  power[0] = 1;
  for(int i=1;i<=200000;i++) {
    power[i] = power[i-1] * 2LL % mod;
  }
  int n;
  std::cin >> n;
  int maxx = 0;
  for(int i=1;i<=n;i++) {
    int x;
    std::cin >> x;
    cnt[x] ++;
    maxx = max(maxx,x);
  }
  ll ans = 0;
  for(int i = maxx;i >= 2;--i) { //倒着遍历保证了下面的容斥的正确性
    ll tmp = 0;
    for(int j = i;j <= maxx; j += i) {
      tmp += cnt[j];
    }
    if(tmp == 0) continue;
    dp[i] = tmp * power[tmp - 1] % mod;
    //例如{4,8}中会算到 2的部分，但可以在4的部分减掉，也就是从大到小算，去掉自身倍数的贡献，类似莫比乌斯反演
    //容斥：2*i，3*i，4*i...
    for(int j = 2 * i; j <= maxx; j += i)
    {
      dp[i] = (dp[i] - dp[j] + mod) % mod;
    }
  //  std::cout << "i=" << i << " " << dp[i] << '\n';
    ans = (ans + dp[i] * i) % mod;
  }
  std::cout << ans << '\n';
  return 0;
}
