/* ************************************************************************
	> File Name: b.cpp
	> Author: caowushang
	> Mail: 15630929347@163.com 
	> Created Time: 2016年11月22日 星期二 20时00分31秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int a[4];
int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int t;
	cin >> t;
	string s;
	while(t--)
	{
		cin >> s;
		int l=s.size();
		bool f=1;
		for(int i=0,j=l-1;i<l/2;i++,j--)
		{
			if(s[i]!=s[j])
			{
				f=0;
				if(s[i]>s[j])
					cout << "heiheihei" << endl;
				else
					cout << "papapa" << endl;
				break;
			}
				
		}
		if(f)
			cout << "mdzz" << endl;
	}
	return 0;
}
