#include<bits/stdc++.h>
using namespace std;
vector< pair<int,int> >a,ans;
multiset<int>s;
 
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,h;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int h,l,r;
		cin>>h>>l>>r;
		a.push_back(make_pair(l,h));
		a.push_back(make_pair(r,-h));
	}
	sort(a.begin(),a.end());//按坐标排序 
//	for(auto x:a)
//	{
//		cout<<x.first<<" "<<x.second<<endl;	
//	} 
	h = 0;
	s.insert(h);//一开始的 h 为 0 
	auto it = a.begin();
	while(it!=a.end())
	{
		auto jt = it;
		do
		{
			if(jt->second > 0)//高 
			{
				s.insert(jt->second);	
			}
			else
			{
				s.erase(s.find(-(jt->second))); 
			}
			jt++;
			
		}while(jt != a.end() && jt->first == it->first);
		
		if(*s.rbegin() != h)
		{
			ans.push_back(make_pair(it->first,h));
			h = *s.rbegin();
			ans.push_back(make_pair(it->first,h));
		}
		it = jt;
	}
	cout<<(int)ans.size()<<endl;//其实点数都是偶数个，因为其实问题求出的都是n条竖线 
	for(int i=0;i<(int)ans.size();i++)
	{
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	return 0;
 } 