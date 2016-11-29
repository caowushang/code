/*************************************************************************
	> File Name: a.cpp
	> Author: caowushang
	> Mail: 15630929347@163.com 
	> Created Time: 2016年10月22日 星期六 13时19分13秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	string a;
	while(cin >> a)
	{
		char ls='a';
		int ans=0;
		for(int i=0;i<a.size();i++)
		{
			ans+=min((ls-a[i]+26)%26,(a[i]-ls+26)%26);
			ls=a[i];
		}
		cout << ans << endl;
	}
	return 0;
}
