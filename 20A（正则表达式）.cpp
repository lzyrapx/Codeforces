#include <bits/stdc++.h>
using namespace std;
int main()
{

	string c;
	cin>>c;
	// regex_replace(, e , ) 在整个字符序列中查找正则表达式e的所有匹配
	//():标记一个子表达式的开始和结束位置。子表达式可以获取供以后使用
    //+：匹配前面的子表达式一次或多次 
	string ans = regex_replace(c,regex("(/)+"),"/");
	
	if(ans[ans.size()-1]=='/' and ans.size() > 1)//如果最后的位置有一个'/' 
	{
    	ans[ans.size()-1]=' ';
	}
	cout<<ans<<endl;
	return 0;
}