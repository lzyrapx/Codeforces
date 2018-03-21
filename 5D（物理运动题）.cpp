#include<bits/stdc++.h>
using namespace std;
//加速度：a
//最大速：v 
//路长：l 
//限速：w 
//限速路段：d 
int main()
{
	double tmp,ans;
	double a,v,l,d,w;
	cin>>a>>v>>l>>d>>w;
	if(w<=v)  ////限制速度小于最大速度时 
	{
		tmp=w*w/2/a;//由零提高到限制速度所需要的路途长度  
		
        if(tmp<d)//如果提高到限制速度还没到达限制标志点  
        {  
            //这一段距离可以加速再减速  
            ans = sqrt(2*tmp/a);  
            double dis=d-tmp;  
            dis/=2;  
            if((v*v-w*w)/2/a <= dis)//如果加速到最高速度还没有到路径的一半，则需要匀速行驶  
            {  
                double t = (v-w)/a;  
                t+=(dis-(v*v-w*w)/2/a)/v;  
                ans+=2*t;  
                tmp=d;  
            }  
            else  //否则不需要匀速行驶  
            {  
                double t = sqrt(2*(tmp+dis)/a)-ans;  
                ans+=2*t;  
                tmp=d;  
            }
        }
        
        else if(tmp>=d &&tmp<=l)  //到了限速标志点  
        {  
            ans=sqrt(2*tmp/a);  
        }  
        
        else if(tmp>l)  //
        {  
            ans=sqrt(2*l/a);  
            tmp=l;  
        }  
  
        if(tmp<l)  
        {  
            double dis = (v*v-w*w)/2/a;  
            if(tmp+dis<=l)  
            {  
                ans+=(v-w)/a;  
                ans+=(l-tmp-dis)/v;  
            }  
            else  
            {  
                ans+=(sqrt(2*a*(l-tmp)+w*w)-w)/a;  
           	}  
        }  
	}
	
	else  //限制速度大于最大速度时 
    {  
        tmp=v*v/2/a;  
        if(tmp<l)  
        {  
            ans=sqrt(2*tmp/a)+(l-tmp)/v;  
        }  
        else if(tmp>l)  
        {  
            ans=sqrt(2*l/a);  
        }  
    }  
    printf("%.5lf\n",ans);
	return 0;
}