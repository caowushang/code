/* ************************************************************************
	> File Name: c.cpp
	> Author: caowushang
	> Mail: 15630929347@163.com 
	> Created Time: 2016年11月28日 星期一 09时58分22秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
const long long mx=1e18+10;
long long a[100];
int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	a[0]=1,a[1]=2;
	for(int i=2;i<100;i++)
	{
		a[i]=a[i-1]+a[i-2];
		if(a[i]>mx)
			break;
	}
	long long n;
	while(cin >> n)
	{
		int ans=0;
		while(a[ans+1]<=n)ans++;
		cout << ans << endl;
	}
	return 0;
}
