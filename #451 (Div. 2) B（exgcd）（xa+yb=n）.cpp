#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5;
const int mod = 1e6+3;
const ll INF =2e15;

// a solution of a * x + b * y = gcd(a,b)
void exgcd(ll a, ll b ,ll &x,ll &y)
{
  if(b==0) {
    x=1,y=0;
    return ;
  }
  exgcd(b,a%b,y,x);
  y -= a / b * x;
}
ll n , a, b;
int main(int argc, char const *argv[]) {
  std::cin >> n >> a >> b;
  // x * a + y * b = n
  ll g = __gcd(a,b);
  if(n % g >= 1) {
    std::cout << "NO" << '\n';return 0;
  }
  n /= g;
  a /= g;
  b /= g;
  ll x,y;
  exgcd(a,b,x,y);
  x *= n; y *= n;
  if(x>=0 && y>=0) {
    std::cout << "YES" << '\n';
    std::cout << x << " " << y << '\n';
    return 0;
  }
  int flag = 0;
  if(y < 0) {
    swap(x,y);
    swap(a,b);
    flag = 1;
  }
  int k = ( -x + b - 1 ) / b;
  x += k * b;
  y -= k * a;
  if(y < 0) {
    std::cout << "NO" << '\n';return 0;
  }
  if(flag==1) {
    swap(x,y);
  }
  std::cout << "YES" << '\n';
  std::cout << x << " " << y << '\n';
  return 0;
}
