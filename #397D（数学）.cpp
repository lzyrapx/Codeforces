#include<bits/stdc++.h>
using namespace std;
/*
因为： 
g(h(x))=x
h(g(x))=f(x)
所以，h(x)=f(f(x)) && 必须有一个 x= f(x)
从而得到 g(x) =g(f(x))
*/

int f[100000+7],g[100000+7];
int h[100000+7];
int main()
{
    int n;
    int hn=0;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>f[i];
    	if(f[i]==i){ //x=f(x) 
    		hn++;
    		g[i]=hn;
    		h[g[i]]=i; //h(g(x))=f(x)=f(x);
		}
	}
	//for(int i=1;i<=n;i++)cout<<"g[f[i]]="<<g[f[i]]<<endl;
	for(int i=1;i<=n;i++){
		if(!g[f[i]])return 0*puts("-1");
	}
	cout<<hn<<endl;      
	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
	for(int i=1;i<=n;i++)cout<<g[f[i]]<<" ";
	cout<<endl;
	
	for(int i=1;i<=hn;i++)
	cout<<h[i]<<" ";
	return 0;
}
