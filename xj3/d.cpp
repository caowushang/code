/*************************************************************************
	> File Name: d.cpp
	> Author: caowushang
	> Mail: 15630929347@163.com 
	> Created Time: 2016年10月06日 星期四 16时46分58秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int t;
	cin >> t;
	for(int ii=1;ii<=t;ii++)
	{
		cout << "Case #" << ii << ": ";
		int n,a,b;
		cin >> n >> a >> b;
		int g=__gcd(a,b);
		int key=n/g-2;
		if(key&1)
			cout << "Yuwgna" << endl;
		else
			cout << "Iaka" << endl;
	}
	return 0;
}
