/* ***********************************************
Author        :caowushang
Created Time  :2016年10月22日 星期六 08时26分06秒
File Name     :h.cpp
************************************************ */

#include <cstdio>
#include <vector>
#include <cmath>
typedef long long ll;
using namespace std;
ll m,k;
vector<ll> pri;
void fen(ll s)
{
	pri.clear();
	for(ll i=2;i<=s;i++)
	{
		if(s%i==0)
		{
			pri.push_back(i);
			while(s%i==0)s/=i;
		}
	}
	if(s>1)
		pri.push_back(s);
}
void rong(ll s,ll x,ll b ,ll &tmp,ll n,ll m)
{
	if(s==0){tmp+=n/x;return;}
	if(m-b>=s)
		for(ll i=b;i<m;i++)
			rong (s-1,x*pri[i],i+1,tmp,n,m);
}
ll calc(ll n)
{
	ll ans=0;
	ll m=pri.size();
	for(ll i=1;i<=m;i++)
	{
		ll tmp=0;
		rong(i,1,0,tmp,n,m);
		ans+=(i&1?1:-1)*tmp;
	}
	return n-ans;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%lld%lld",&m,&k)!=EOF)
	{
		fen(m);
		ll l=1,r=1L<<50;
		while(l<r)
		{
			ll m=(l+r)/2;
			if(calc(m)<k)
				l=m+1;
			else 
				r=m;
		}
		printf("%lld\n",l);
	}
    return 0;
}
