/*************************************************************************
	> File Name: b.cpp
	> Author: caowushang
	> Mail: 15630929347@163.com 
	> Created Time: 2016年10月04日 星期二 11时14分31秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int n;
	cin >> n;
	char x='_';
	int a1=0,a2=0;
	int c1=0;
	bool ip=0;
	char y;
	for(int i=0;i<n;i++)
	{
		y=x;
		cin >> x;
		if(ip)
		{
			if(x=='_'||x==')')
			{
				if(y!='_'&&y!='(')
					a2++;
			}
			if(x==')')
				ip=0;
		}
		else
		{	
			if(x!='_'&&x!='(')
				c1++,a1=max(a1,c1);
			else
			{
				c1=0;
				if(x=='(')
					ip=1;
			}
		}
	}
	cout << a1 << " " << a2 << endl;
	return 0;
}
