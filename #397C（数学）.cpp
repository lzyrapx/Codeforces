#include<bits/stdc++.h>
using namespace std;
//(a,b)最多被分成(x,k)或者(k,x)的和 
int main()
{
    int a,b,k;
    cin>>k>>a>>b;
    if(a<k&&b%k!=0)return 0*puts("-1");
    if(b<k&&a%k!=0)return 0*puts("-1");
    cout<<a/k+b/k<<endl;
	return 0;
}