/* ************************************************************************
	> File Name: a.cpp
	> Author: caowushang
	> Mail: 15630929347@163.com 
	> Created Time: 2016年11月24日 星期四 18时12分09秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	long long n,a,b,c;
	while(cin >> n >> a >> b >> c)
	{
		if(n%4==0)
		{
			cout << 0 << endl;
			continue;
		}
		long long x=4-(n%4);
		long long ans;
		if(x==1)
			ans=min(a,min(b+c,c*3));
		else if(x==2)
			ans=min(b,min(a*2,c*2));
		else
			ans=min(c,min(a*3,a+b));
		cout << ans << endl;
	}

	return 0;
}
