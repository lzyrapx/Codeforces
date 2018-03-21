#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
int a[123456];
int main()
{
	cin>>n>>m>>k;
//	if(k<=2 || k >=n-1 ){
//		cout<<"-1"<<endl;
//		exit(0);
//	}

	//割点后，分成2个完全图 
	//一个具有n个顶点的无向完全图的边数为n*(n-1)/2,删除一个点，所以变成n-1个点 
	// a connected graph doesn't exist if the number of edges is less than n-1.
	
	if(m > (n-1)*(n-2)/2+1 || m <n-1){
		cout<<"-1"<<endl;
		exit(0);
	}
	int last=0;  
    for(int i=1;i<=n;i++)  
    {  
        if(i!=k)  
    	{  
            printf("%d %d\n",i,k);  
            last=i;  
        }  
    }  
    m-=(n-1);  
    for(int i=1;i<last && m != 0;i++)  
    {  
        for(int j=i+1;j<last && m!=0;j++)  
        {  
        	if(i!=k&&j!=k)  
            {  
                printf("%d %d\n",i,j);  
                m--;  
        	}  
                      
    	}  
    }  
	return 0;
}