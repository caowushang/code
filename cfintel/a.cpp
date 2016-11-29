/*************************************************************************
	> File Name: a.cpp
	> Author: caowushang
	> Mail: 15630929347@163.com 
	> Created Time: 2016年10月08日 星期六 20时16分38秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
map<string ,int> m;
int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	m["monday"]=0,m["tuesday"]=1,m["wednesday"]=2,m["thursday"]=3,m["friday"]=4,m["saturday"]=5,m["sunday"]=6;
	string a,b;
	cin >> a >> b;
	if((m[a]+28)%7==m[b]||(m[a]+30)%7==m[b]||(m[a]+31)%7==m[b])
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
