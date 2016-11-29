/* ***********************************************
Author        :caowushang
Created Time  :2016年10月12日 星期三 12时31分04秒
File Name     :a.cpp
************************************************ */

#include<cstdio>
#include<iostream>
#include<set>
#include<algorithm>
#include<cmath>
typedef long long ll;
using namespace std;
set<ll> S,ans,tmp;
void fen(ll n)
{
	for(ll i=2;i*i<n;i++)
	{
		if(n%i==0)
		{
			ll x=1;
			while(n%i==0)
			{
				x*=i;
				n/=i;
			}
			S.insert(x);
		}
	}
	if(n>1)
		S.insert(n);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll gc,lc;
	scanf("%lld%lld",&gc,&lc);
	ll n=lc/gc;
	fen(n);
	set<ll>::iterator i,j;
	ll mx=sqrt(n+0.5);
	ans.insert(1);
	for(i=S.begin();i!=S.end();i++)
	{
		tmp.clear();
		for(j=ans.begin();j!=ans.end();j++)
		{
			ll x=(*i)*(*j);
			if(x<=mx)
				tmp.insert(x);
		}
		for(j=tmp.begin();j!=tmp.end();j++)
			ans.insert(*j);
	}
	i=ans.end();
	i--;
	ll a=*i;
	ll b=n/a;
	printf("%lld %lld\n",a*gc,b*gc);
    return 0;
}
