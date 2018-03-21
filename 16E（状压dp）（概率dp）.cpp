#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double prob[18][18];
double f[1<<18];
int cnt;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		cin>>prob[i][j];
		}
	}
	f[(1<<n)-1] = 1;//所有鱼都在，初始化概率都是 1 
	for(int i=(1<<n)-1;i>0;--i)//遍历所有状态 
	{
		cnt = 0;
		for(int j=0;j<n;j++) //遍历获胜的鱼的编号
		{
			if(i & (1<<j))//j号鱼还活着
			{
				cnt++;
			}
		}
		for(int j=0;j<n;j++)//遍历获胜鱼j要吃掉的k号鱼  
		{
			if((i&(1<<j))==0)continue;//j号鱼不存活 
			
			for(int k=j+1;k<n;k++) 
			{
				if((i&(1<<k))==0)continue;//k号鱼不存活 
				//f(j吃掉k) = f(j和k同时存在) * f(j战胜k) * f(j和k相遇) 
				//1<<k : 第k位的1一定存在 
				f[i - (1<<k)] += f[i] * prob[j][k] * 1.0 / (cnt * (cnt - 1) / 2);//k被吃掉 
				f[i - (1<<j)] += f[i] * prob[k][j] * 1.0 / (cnt * (cnt - 1) / 2);//j被吃掉 
			}
		}
	}
	
	for(int i=0;i<n-1;i++)
	{
		printf("%.6f ",f[1<<i]);//分别输出只有第i条鱼活着的概率
	}
	printf("%.6f\n",f[1<<(n-1)]);
    return 0;
}