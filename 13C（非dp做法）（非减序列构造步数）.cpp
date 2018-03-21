#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
long long ans;
priority_queue<int>q;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		q.push(x);
		if(q.top()>=x)//保证非递减序列
		{  
		//	cout<<"top="<<q.top()<<endl;
			ans+= q.top() - x;
		//	cout<<"ans="<<ans<<endl;
			q.pop();
			q.push(x);
		}
	} 
	printf("%lld",ans);
	return 0;
} 