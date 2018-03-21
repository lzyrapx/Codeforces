/*
题意：给定n种货币，每种货币数量无限。 现在要求以最少的货币数目表示一个数S。 一种方法当然是DP求一个最优解了， 
当然正 常人的做法是贪心：每次取最大的不超过当前待表示数的货币。 
现在，你的任务是证明正常人的表示法不一定最优：找到最小的S，使得正常人的表示法 比理论最优解差，或说明这样的S不存在。 n ≤ 300

题解：这是一道论文题，设M(s)为数s的最优表示，G(s)为其贪心表示，
那么我们要找第一个M(s) < G(s) 的s,对于这样的s，M(s) 和 G(s) 中 一定不存在公共项（ai系数同时大于0）,
设M(s)中最大项为bi,G(s)中最大项为ai,则有bi < ai,且M(s) = G(x-bi) + bi，又因M(s)与G(s)不存在公共项（否则s可以更小），
所以 G(x-bi) 加上 bi项后变成 G(x) 的过程中必定发生了进位，且进位后ai = 1（两个小于ai的数相加一定小于2*ai,
这表明最后s一定是大于ai小于2*ai）,然后我就不会证了，设bj是M(s)中的最小项，
正解中有个结论是 M(s-bj)中的非零项系数一定和G(ai-1)相等，所以我们枚举ai和bj就可以了。
*/ 
#include<bits/stdc++.h>
using namespace std;
int n,ans,a[500],b[500],c[500];  
int solve(int x)  
{  
    int ans = 0;  
    for(int i = 1;i <= n;i++)  
    {  
        b[i] = x / a[i];  
        ans  += b[i];  
        x %= a[i];  
        if(!x) break;   
    }   
    return ans;  
}  
int main()  
{  
    ans = 2e9;  
    cin>>n;  
    for(int i = 1;i <= n;i++) cin>>a[i];  
    
    for(int i = 1;i < n;i++)  
    {  
        solve(a[i]-1);   
        for(int i = 1;i <= n;i++) c[i] = b[i];  
        for(int j = i+1;j <= n;j++)  
        {  
            int temp = 0,temp2 = 0;  
            for(int k = 1;k <= j;k++)   
            {  
                temp2 += a[k]*c[k];  
                temp += c[k];  
            }  
            temp2 += a[j],temp++;  
            if(solve(temp2) > temp) ans = min(temp2,ans);  
        }  
    }  
    if(ans == 2e9) cout<<-1<<endl;  
    else cout<<ans<<endl;  
    return 0;
}  
