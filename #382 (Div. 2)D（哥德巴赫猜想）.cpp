#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+5;
const int mod = 1e9+7;
const ll INF =2e15;
int a[maxn],b[maxn];
int vis[maxn];
int ans[maxn];
std::map<int, int> mp;

/*
你有n元钱，你需要交税，交锐的价格为n 的最大因子（不等于n），为了缩小税钱，
你可以拆成多个钱相加的形式，但是不能拆出1来，问你最少交多少钱？
*/
int isprime(ll x)
{
  for(ll i=2;i*i<=x;i++) {
    if(x%i==0)return 0;
  }
  return 1;
}
int main(int argc, char const *argv[]) {

  int n;
  std::cin >> n;
  if(n==2) std::cout << "1" << '\n',exit(0);
  //哥德巴赫猜想：任何大于 2 的偶数必定写成两个质数相加的形式
  if(n%2==0){
    std::cout << "2" << '\n';
  }
  else {
    if(isprime(n)) std::cout << "1" << '\n';
    else if(isprime(n-2)) {
      std::cout << "2" << '\n';
    }
    else std::cout << "3" << '\n';
  }
  return 0;
}
