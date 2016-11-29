/*************************************************************************
	> File Name: sub.cpp
	> Author: caowushang
	> Mail: 15630929347@163.com 
	> Created Time: 2016年10月05日 星期三 16时24分36秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

string sub(string &a,string &b)
{
	string c="";
	int x=0;
	int al=a.size(),bl=b.size();
	for(int i=al-1,j=bl-1;i>=0;i--,j--)
	{
		int bj=x;
		x=0;
		if(j>=0)
			bj+=b[j]-'0';
		int js=a[i]-'0';
		if(js<bj)
			js+=10,x=1;
		c=char(js-bj+'0')+c;
	}
	int l=0;
	while(c[l]=='0')l++;
	string ans=c.substr(l);
	if(ans.size()==0)
		return "0";
	else
		return ans;
}
int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	string a,b;
	while(cin >> a >> b)
	{
		cout << sub(a,b) << endl;
	}
	return 0;
}
