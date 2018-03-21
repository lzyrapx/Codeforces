#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
map<int, int>mp[123456];

int p[123456],dp[123456];
int res[123456];
/*
题意： 
给定长度为n的四元组序列 (v_i ,c_i ,l_i ,r_i )  
要求选出一个子序列（也就是原序列去掉若干元素后得到的序列）， 使得满足：  
1.子序列中所有的四元组c_i + l_i + r_i 均相等  
2.第一个元素的l_i = 0， 最后一个元素的r_i = 0  
3.第i个元素的l_i 等于前i-1个元素的c_i 之和。  
我们的任务是，最大化选出的子序列元素v i 之和。要求输出方案。 

题解： 
因为题目的约束非常强，可以发现，一个元素j能成为i的后继元素，当且仅当l_j = l_i +c_i ，  
而且题目规定了必须选出一个子序列，因此有天然的序的关系.  
这时，dp就非常显然了。  
我们用dp[i]表示：当前考虑到了i，且选择了i时，最大的v值之和。  
显然有 dp[i] = max{dp[j] 其中 j > i 且 l_j = l_i + c_i } + v_i  
用个map维护l_j为某个值时最大的dp[j]即可做到O(NlogN)。   
*/
//dp[i]表示：当前考虑到了i，且选择了i时，最大的v值之和
int main()
{
    int v,c,l,r,n;      
    cin>>n;
    int cur=0;
    for(int i = 1; i<=n; i++)
	{
        cin>>v>>c>>l>>r;
        if(r + c < 123456)
		{
            int idx = mp[l][r+c];
            if(idx || l==0)
			{
                dp[i] = dp[idx] + v;
                p[i] = idx;
             //   cout<<"idx="<<idx<<endl;
                if(dp[i] > dp[ mp[l + c][r] ])
				{
                    mp[l + c][r] = i;
                }
                if(r==0 && dp[i] > dp[cur])
				{
                    cur = i;
                   // cout<<"cur="<<cur<<endl; 
                }
            }
        }
    }
    int num=0;
    while(cur)
	{
        res[num] = cur;
        cur = p[cur];
        ++num;
    }
    cout<<num<<endl;
    for(int i = num-1; i>=0;--i)
	{
       cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}