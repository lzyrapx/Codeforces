#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000005;
ll inv[maxn],fac[maxn],dp[maxn],sum[maxn];
const int mod =1e9+7;

ll qpower(ll a,ll b){
  ll res = 1;
  while(b)
  {
    if(b&1)res = res*a%mod;
    b>>=1;
    a= a*a%mod;
  }
  return res;
}

int main(int argc, char const *argv[]) {
  ll n,k;
  ll ans = 0;
  cin>>n>>k;
  if(k+1>=n){
    printf("0\n");
    exit(0);
  }
  fac[0] = 1;
  for (int i = 1; i <=n; i++) {
    fac[i] = (fac[i-1] * i) %mod;
  }
  inv[n] = qpower(fac[n],mod-2);
  for(int i=n-1;i>=0;i--){
    inv[i] = inv[i+1] *(i+1);
    inv[i] %= mod;
  }
  memset(dp,0,sizeof(dp));
  memset(sum,0,sizeof(sum));

  for(int i=k+2;i<=n;i++){
    dp[i] = (i-k-1 + (sum[i-1] - sum[i-k] +mod)%mod)%mod; //前缀sigma
    dp[i] = (dp[i] * fac[i-2]) % mod;
    // cout << i << " " << dp[i] << endl;
    sum[i] = sum[i-1] + (dp[i] * inv[i-1])%mod;
    sum[i] %= mod;
    ans += (((dp[i] * fac[n-1]) % mod) * inv[i-1])%mod;
    ans %= mod;
  }
  cout<<ans<<endl;
  return 0;
}
