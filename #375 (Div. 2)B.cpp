#include<cstdio>
using namespace std;
const int N=1010;
int i,j,k,n,m,num,ans1,ans2;
char s[N];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	s[++n]='_';
	for (i=1;i<=n;i++)
	{
		if (s[i]=='_' || s[i]=='(' || s[i]==')')
		{
			if (num && k) ans2++;
			if (!num && k>ans1) ans1=k;
			k=0;
		}
		else k++;
		if (s[i]=='(') num++;
		if (s[i]==')') num--;
	}
	printf("%d %d\n",ans1,ans2);
}