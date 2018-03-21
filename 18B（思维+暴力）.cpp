#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//在数轴上，步长为d，如果跳到某个平台的右边而且在下一个平台之间左边的缝里.
//那就掉下去了，就是输出掉下去的坐标 
int main()
{
    ll n,d,m,l;
    ll step;
    while(cin>>n>>d>>m>>l)
    {
        ll min,max;
        for(int i=0;i<n;i++)
        {
            min=i*m+l;//第i个平台右边的边界
            max=(i+1)*m;//第i+1个平台左边的边界
            step=(min+d)/d;
            if(step*d<max) break;
        }
        cout<<step*d<<endl;
    }
    return 0;
}