#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  if(n==2) {
    std::cout << "3" << '\n';return 0;
  }
  if(n==4) {
    std::cout << "6" << '\n';
  }
  //n/2(射死 b 队的人)+n/2(射死 a 队的人)+n/2（ b 队剩下的人）
  if(n>=6) {
    std::cout << n / 2 * 3 << '\n';
  }
  return 0;
}
