/*************************************************************************
	> File Name: d.cpp
	> Author: caowushang
	> Mail: 15630929347@163.com 
	> Created Time: 2016年10月02日 星期日 16时37分45秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
typedef long long ll;
ll a[maxn];
ll n,k,x;
struct pp
{
	ll p;
	pp(int i=0):p(i){}
	bool operator < (const pp&t)const
	{
		return abs(a[p]) < abs(a[t.p]);
	}
};
int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	scanf("%I64d%I64d%I64d",&n,&k,&x);
	bool b=0;
	int z=0,f=0;
	multiset<pp> s;
	for(int i=0;i<n;i++){
		scanf("%I64d",&a[i]);
		if(x*k>abs(a[i]))
			b=1;
		if(a[i]<0)
			f++;
		else
			z++;
		s.insert(pp(i));
	}
	set<pp>::iterator it;
	if(f&1)
	{
		while(k--)
		{
	//		cout << 1 << endl;
			int p=s.begin()->p;
			s.erase(s.begin());
			a[p]+=(a[p]>=0?1:-1)*x;
			s.insert(pp(p));
		}
	}
	else
	{
		if(!b)
		{
			while(k--)
			{
	//			cout << 2 << endl;
				int p=s.begin()->p;
				s.erase(s.begin());
				a[p]+=(a[p]>=0?-1:1)*x;
				s.insert(pp(p));
			}
		}
		else
		{
	//		cout << 3 << endl;
			int p=s.begin()->p;
			s.erase(s.begin());
			while(a[p]>=0)
			{
				a[p]+=(a[p]>=0?-1:1)*x;
				k--;
			}
			s.insert(pp(p));
			while(k--)
			{
				int p=s.begin()->p;
				s.erase(s.begin());
				a[p]+=(a[p]>=0?1:-1)*x;
				s.insert(pp(p));
			}
		}
	}
	for(int i=0;i<n;i++)
		printf("%I64d ",a[i]);
	puts("");
	return 0;
}
