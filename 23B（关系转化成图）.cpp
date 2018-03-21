the answer is not more than N - 2. We'll prove that it's possible for N - 2 people to stay (of course, if N > 1). 
The graph of friendship will be the following: take a complete graph on N vertices and delete one edge. 
Then the degrees of two vertices equal N - 2, and other degrees equal N - 1. After the first two vertices are removed, 
we have a complete graph on N - 2 vertices, and all degrees equal N - 3, which means that no one else will leave.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		if(n==1)cout<<0<<endl;
		else 
		cout<<n-2<<endl;	
	}
	
	return 0;
}