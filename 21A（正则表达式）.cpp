#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	string s;
	cin>>s; 
	//[]:表示包含的字符类型
	//{}：表示长度
	//mike@codeforces.com：YES
	//john.smith@codeforces.ru/contest.icpc/12 ： NO 
	//johnsmith@codeforces/ru/contest.icpc/12 ： NO
	//007@en.codeforces.com/contest ： YES 
	//0.07@en.codeforces.com/contest : NO
	
	regex re1("[A-Za-z0-9_]{1,16}@[A-Za-z0-9_.]{1,32}(/[A-Za-z0-9_]{1,16})?");
	regex r3("[A-Za-z0-9_]{1,16}@[A-Za-z0-9_]{1,16}(.[A-Za-z0-9_]{1,16})*(/[A-Za-z0-9_]{1,16})?");

	if (regex_match(s, r3) && regex_match(s,re1))
	{
		cout << "YES" <<endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}