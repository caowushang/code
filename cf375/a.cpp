/*************************************************************************
	> File Name: a.cpp
	> Author: caowushang
	> Mail: 15630929347@163.com 
	> Created Time: 2016年10月04日 星期二 10时50分50秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int x1,x2,x3;
	cin >> x1 >> x2 >> x3;
	int ans=1111111;
	for(int i=1;i<=100;i++)
	{
		int xx=abs(i-x1)+abs(i-x2)+abs(i-x3);
		ans=min(ans,xx);
	}
	cout << ans << endl;
	return 0;
}
