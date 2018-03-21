#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
ll dp[N][2];
ll a[N];
ll ans = 0;
vector<int> G[N];
void dfs(int cur, int fa, int bit)
{
    ll res = 0;
    int b = (a[cur] >> bit) & 1;//取得当前的a[cur]在第bit位是0还是1
    //这里好巧妙啊... 
    dp[cur][b] = 1;//初始化
    dp[cur][b ^ 1] = 0;//初始化
    
    for(auto v:G[cur]){
    	if(v!=fa){
    		dfs(v, cur, bit);
        	res += dp[cur][0] * dp[v][1] + dp[cur][1] * dp[v][0];//统计子节点到cur的路径上异或和，只需算1^0与0^1即可 
        	dp[cur][b ^ 0] += dp[v][0];//更新异或操作后的状态值
        	dp[cur][b ^ 1] += dp[v][1];//更新异或操作后的状态值
		}
	}	
	/*
    for (int i = 0; i<G[cur].size(); i++)
	{
        int v = G[cur][i];
        if (v == fa)continue;
        dfs(v, cur, bit);
        q += dp[cur][0] * dp[v][1] + dp[cur][1] * dp[v][0];
        dp[cur][b ^ 0] += dp[v][0];
        dp[cur][b ^ 1] += dp[v][1];
    }
    */
    ans += (res << bit);//更新答案
}
int main()
{
    int n, u, v;
    cin >> n;
    for (int i = 1; i <= n; i++){
	    cin >> a[i];
        ans += a[i];
    }
    for (int i = 0; i<n - 1; i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    //由于权值最大为1e6，所以只需要枚举到20位。2^20=1048576 
    for (int i = 0; i <= 20; i++)
        dfs(1, 0, i);
   return 0*printf("%I64d\n",ans);
}
/*
5
1 2 3 4 5
1 2
2 3
3 4
3 5

52
*/