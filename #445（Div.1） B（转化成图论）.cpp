#include <bits/stdc++.h>
/*
给出十万个字符串，总长度不超过十万，要求构造一个字符串，使得所有给出的字符串在这个串当中都是出现次数最多子串。输出长度最短的答案。如果有多个答案，输出字典序最小的。
*/
/*
把每个给出的字符串中，相邻的两个字符连上一条有向边。 
首先我们要知道，如果有解，那么这个解应该是若干条链贪心加和。所以出现环则无解。 
其次每个点的出入度最大只能为1，否则无法满足题意。 
*/
int main(int argc, char const *argv[]) {
  int n;
  std::cin>>n;
  std::vector<int> g(255,-1);
  std::vector<int> in(255);
  std::vector<bool> vv(255);
  for(int i=0;i<n;i++){ //很多条链组成的森林
    std::vector<bool> v(255);
    std::string s;
    std::cin>>s;
    v[s[0]] = vv[s[0]] = true;
    for(int i=1;i<(int)s.size();i++){
      char c = s[i];
      if(v[c]==true || ((g[s[i-1]] != -1 || in[c]==true) && g[s[i-1]] != s[i]))//不能有环和自环，否则答案就是NO
      {
        std::cout << "NO" << '\n';
        exit(0);
      }
      v[c] = true;
      g[s[i-1]]  = s[i];
      vv[c] = true;
      in[c] ++;
    }
  }
  int cnt = 0;
  for(auto x : vv){
    if(x==true)
      cnt += 1;
  }
  std::string s;
  for(int i='a';i<='z';i++){ //遍历所有链，把这些链构成的若干个词连起来就是答案
    if (!in[i] && vv[i]) {
      for(int j=i;j!=-1;j=g[j])
      {
        s += char(j);
      }
    }
  }
  if ((int)s.size()!=cnt) {
    std::cout << "NO" << '\n';
    exit(0);
  }
  std::cout << s << '\n';
  return 0;
}
