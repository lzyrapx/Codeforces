
/*题意：这个内存条一共有连续的 m 个块。给你n个操作。
alloc x，就是你要产生一个块，这个块的大小是x。前提是：存在一个连续区间可以放下这个块。那就放下去，而且要求尽量放在前面。如果不能放就输出NULL。不然就输出一个数，从1开始。
erase x，就是把编号为 x 的块擦除。非法擦除就输出ILLEGAL_ERASE_ARGUMENT。
defragment，就是重新排序，把每个块都尽量放在前面，让后面的都是空的。
题解：
模拟题。注意一下细节，WA一两次就可以了....QAQ
*/
#include<bits/stdc++.h>
using namespace std;
char s[100];
int n,m,ans;
int blocks=0;
int a[1010];
int alloc(int x)
{
	for(int i=1;i<=m;i++)
	{
		int j=i;
		int num=0;
		while(a[j]==0 && num !=x && j<=m)
		{
			num++;
			j++;
		}
		if(num!=x)
		{
			i=j;
		}
		else
		{
			blocks++;
			for(int k=i;k<j;k++)
			{
				a[k]=blocks;
			}
			return blocks;
		}

	}
	return 0;
}
int earse(int x)
{
	if(x<=0)
	{
		return -1;
	}
	int flag=0;
	for(int i=1;i<=m;i++)
	{
		while(a[i]==x)
		{
			a[i++]=0;
			flag=1;
		}
		
	}
	if(flag==1)
	{
		return -2;
	}
	return -1; //非法擦除 
}
int defragment()
{
	for(int i=1;i<=m;i++)
	{
		if(a[i]==0)
		{
			for(int j=i+1;j<=m;j++)
			{
				if(a[j])
				{
					swap(a[i],a[j]);break;
				}
			}
		}
	}
	return -5;
}
int main()
{
	int x;
	cin>>n>>m;
	memset(a,0,sizeof(a));
	while(n--)
	{
		scanf("%s",&s);
		if(s[0]=='a')
		{
			cin>>x;
			ans=alloc(x);
		}
		else if(s[0]=='e')
		{
			cin>>x;
			ans=earse(x);
		}
		else if(s[0]=='d')
		{
			ans=defragment();
		}
		
		if(ans==0){
			printf("NULL\n");
		}
		else if(ans==-1)
		{
			printf("ILLEGAL_ERASE_ARGUMENT\n");
		}
		else if(ans>=1)
		{
			printf("%d\n",ans);
		}
	}
	return 0;
}