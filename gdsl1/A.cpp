/*************************************************************************
  > File Name: A.cpp
  > Author: caowushang
  > Mail: 15630929347@163.com 
  > Created Time: 2016年10月18日 星期二 19时03分55秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,n;
ll ans,tmp;
ll a[30];
ll lcm(ll a,ll b)
{
	return a*b/__gcd(a,b);
}
void rong(ll s,ll x,ll b)
{	
	if(s==0)
	{
		tmp+=n/x;
		return;
	}
	if(m-b>=s)
		for(ll i=b;i<m;i++)
		{
			rong(s-1,lcm(x,a[i]),i+1);
		}
}
int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	while(scanf("%lld%lld",&n,&m)!=EOF)
	{
		for(ll i=0;i<m;i++)
			scanf("%lld",&a[i]);
		ans=0;
		for(ll i=1;i<=m;i++)
		{
			tmp=0;
			rong(i,1,0);
			ans+=(i&1?1:-1)*tmp;
		}
		printf("%lld\n",n-ans);

	}
	return 0;
}
