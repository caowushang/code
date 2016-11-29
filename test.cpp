/*************************************************************************
	> File Name: test.cpp
	> Author: caowushang
	> Mail: 15630929347@163.com 
	> Created Time: 2016年10月02日 星期日 14时54分30秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	ll a,b,c;
	while(cin >> a >> b >> c)
	{
		set<ll> s;
		for(ll i=0;i<=a;i++){
			for(ll j=0;j<=b;j++){
				for(ll k=0;k<=c;k++)
				{
					s.insert(i+j*2+k*3);
				}
			}
		}
		set<ll>::iterator it;
		for(it=s.begin();it!=s.end();it++)
			cout << *it << " ";
		cout << endl;
		cout << s.size()-1 << endl;
	}
	return 0;
}
