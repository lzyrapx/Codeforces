//#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int read()
{
	int v = 0, f = 1;
	char c =getchar();
	while( c < 48 || 57 < c ){
		if(c=='-') f = -1;
		c = getchar();
	}
	while(48 <= c && c <= 57) 
		v = v*10+c-48, c = getchar();
	return v*f;
}
int a[10005],b[10005];
int main()
{
	int n;
	double w,v,u;
	scanf("%d%lf%lf%lf",&n,&w,&v,&u);
	int flag1=1,flag2=1;
	double ans= 0;
	for(int i=1;i<=n;i++){
		
		scanf("%d%d",&a[i],&b[i]);
		if(a[i]*u>b[i]*v)flag1 =0;
		if(a[i]*u<b[i]*v)flag2 =0;
		//如果他到达某一点比汽车早，可以直接走，
		//如果他到达某一点比汽车迟，可以直接走
		//综上，可以得出：a[i]/v+(w-b[i])/u
		 ans=max(ans,a[i]/v+(w-b[i])/u);
	}
	if(flag1+flag2>0)printf("%.10lf\n",w/u);//最小时间
	else printf("%.10f\n",ans);
	return 0;
}