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
#define maxn 200100

int v[maxn*4];
bool rev[maxn*4];
int in[maxn],out[maxn];
int tot;
int b[maxn],a[maxn];
void push_up(int rt)
{
    v[rt] = v[rt<<1] + v[(rt<<1)|1];
}
void build(int rt,int l,int r)
{
    if(l==r)
    {
        v[rt]=a[l];
        return;
    }
    int mid =(r+l)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    push_up(rt);
}
void change(int rt,int l,int r)
{
    rev[rt]^=1;
    v[rt]=(r - l + 1) - v[rt];
}
/*
延迟标记：每个节点新增加一个标记，记录这个节点是否进行了某种修改(这种修改操作会影响其子节点)，
对于任意区间的修改，我们先按照区间查询的方式将其划分成线段树中的节点，然后修改这些节点的信息，
并给这些节点标记上代表这种修改操作的标记。在修改和查询的时候，如果我们到了一个节点rt，并且决定考虑其子节点，
那么我们就要看节点rt是否被标记，如果有，就要按照标记修改其子节点的信息，
并且给子节点都标上相同的标记，同时消掉节点rt的标记。
*/
void push_down(int rt,int l,int r)
{
    if(rev[rt])//延迟标志
    {
    	int mid = (r+l)>>1;
        change(rt<<1,l,mid);
        change(rt<<1|1,mid+1,r);
        //传递后，当前节点标记域清空
        rev[rt]=0;
    }
}
void update(int rt,int l,int r,int y1,int y2)
{
    if(y1<=l&&y2>=r)
    {
        change(rt,l,r);
        return;
    }
    int mid = (r+l)>>1;
    push_down(rt,l,r);//延迟标记向下传递
    if(y1<=mid) update(rt<<1,l,mid,y1,y2);
    if(y2>mid) update(rt<<1|1,mid+1,r,y1,y2);
    push_up(rt);
}
int query(int rt,int l,int r,int y1,int y2)
{
    if(y1<=l&&y2>=r) return v[rt];
    int ans=0;
    push_down(rt,l,r);//延迟标记向下传递
    int mid = (r+l)>>1;
    if(y1<=mid) ans+=query(rt<<1,l,mid,y1,y2);
    if(y2>mid) ans+=query(rt<<1|1,mid+1,r,y1,y2);
    return ans;
}
vector<int>g[maxn];

void dfs(int u)//dfs序 
{
    in[u]=tot;
    for(auto v:g[u]){
    	tot++;
    	dfs(v);
	}  
    out[u]=tot;
}
int main()
{
	int n;
	n=read();
	for(int i=2;i<=n;i++)
	{
		int x;
		x=read();
		g[x].push_back(i);
	}
	tot = 1;
	dfs(1);//dfs序 

	for(int i=1;i<=n;i++)
	{
		b[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		a[in[i]] = b[i];
	}
	build(1,1,n);
	int q;
	q=read();
	while(q--)
	{
		char op[5];
		int u;
		scanf("%s%d",op,&u);
		if(op[0]=='g')cout<<query(1,1,n,in[u],out[u])<<endl;
		else update(1,1,n,in[u],out[u]); 
	}
	return 0;
}
