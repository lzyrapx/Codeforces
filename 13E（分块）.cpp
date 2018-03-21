#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize ("O3")
typedef long long ll;
const int lowbit(int x) { return x&-x; }
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
/*
ios::sync_with_stdio(0);
cin.tie(0);
*/
/***************************timer******************************/
struct timer
{
   double t;
   timer() { t=clock(); }
   ~timer() { printf("\nruntime %.3f s\n", get_time()); }
   double get_time() { return (clock()-t)/CLOCKS_PER_SEC; }
};
/*************************************************************/
int sz = 0;
int n;
int a[123456];
int jump[123456];
int cnt[123456];
inline void build(int x)
{
	int l = x * sz;
	int r = min((x+1)*sz,n);
	for(int i = r - 1;i >= l;--i)
	{
		if((i + a[i] )>= r)//在块外 
		{
			jump[i] = i;
			cnt[i] = 0;
		}
		else//块内 
		{
			jump[i] = jump[i + a[i]];
			cnt[i] = cnt[i + a[i]] + 1;
		}
	}
}
int main()
{
	int m;
//	cin>>n>>m;
	n=read(),m=read();
	for(int i=0;i<n;i++){
		//cin>>a[i];
		a[i]=read();
	}
	sz = (int)sqrt(n*1.0);
	for(int i=0;i*sz<n;i++)
	{
		build(i);
	}
//	cout<<"finish"<<endl;
	while(m--)
	{
		int c;
	//	cin>>c;
		c=read();
		if(c==1)
		{
			int res = 0;
			int cur;
		//	cin>>cur;
		 	cur=read();
			cur--;
		//	cout<<"finish"<<endl;
			while(cur < n)
			{
				res += cnt[cur] + 1;
				cur = jump[cur];
				if(cur + a[cur] >= n) break;
				cur += a[cur];	
			}
			//cout<<cur + 1<<" "<<res<<endl;
			//最后一个球的下标 + 跳的次数 
			printf("%d %d\n",cur+1,res);
		}
		else if(c==0)
		{
			int v,x;
			//cin>>v>>x;
			v=read(),x=read();
			v--;
			a[v] = x;
			build(v / sz);//v在哪一块中 
		}
	}
	return 0;
}
