#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000010;
int H[maxn], L[maxn], R[maxn], C[maxn];
int n;
/*
首先要拆环成链，将山的序列改变，第一座山是最高的山。 
其次是统计对于这个序列的L数组和R数组。表示：
First hill to the left of the x, which is strictly higher than x.
First hill to the right of the x, which is strictly higher than x.
生成C数组：
All hills that are as high as x and are located between x and y.
L[i]表示i左侧比第一个比i高(或等)的位置，
R[i]表示i右侧第一个比i高(或等)的位置，
C[i]表示从i到 R[i]的左开右闭区间内高度等于i的山的数目
L和 R是位置，而 C是数目
最后统计答案。
那么对于一座山i而言，它可以和 L[i] 和 R[i]都构成能互相看见的pair，并且和i到 R[i]之间所有高度等于i的山构成能互相看见的pair。
所以问题就是计算 L数组、R数组和 C数组.
L[i]==0 && R[i]==N 时只需要算一个,因为重复了 
*/ 
int main()
{
    scanf("%d",&n);  
    for (int i = 0; i < n; i++)
	{
		scanf("%d",&H[i]);//不取消同步的cin会T 
	} 			    
    rotate(H, max_element(H, H + n), H + n);
    //5 3 1 2 4
    H[n] = H[0];
    for (int i = n - 1; i >= 0; --i)
	{
		R[i] = i+1;
		while(R[i] < n && H[R[i]] < H[i])
		{
			R[i] = R[R[i]];
		}   
		 
        if (R[i] < n && H[R[i]] == H[i])
		{
        	C[i] = C[R[i]] + 1;
			R[i] = R[R[i]];
		}
		
    }
    //for(int i=0;i<=n;i++)printf("L[%d]=%d ",i,L[i]);cout<<endl;
    //for(int i=0;i<=n;i++)printf("R[%d]=%d ",i,R[i]);cout<<endl;
    //for(int i=0;i<=n;i++)printf("C[%d]=%d ",i,C[i]);cout<<endl;
    ll ans = 0;
    for (int i = 0; i < n; i++)
	{
        ans += C[i];
        if (H[i] == H[0]) continue;
        
        L[i] = i - 1;
        while(L[i] > 0 && H[L[i]] <= H[i])
        {
        	L[i] = L[L[i]];
		}
        ans += 2;
        if (L[i] == 0 && R[i] == n)
		{
        	ans--;
		}
    }
    //for(int i=0;i<=n;i++)printf("L[%d]=%d ",i,L[i]);cout<<endl;
    printf("%I64d\n",ans);
    return 0;
}