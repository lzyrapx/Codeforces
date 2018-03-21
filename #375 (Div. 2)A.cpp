#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x[3];
    cin>>x[0]>>x[1]>>x[2];
    sort(x,x+3);
    cout<<x[2]-x[0];
    return 0;
}