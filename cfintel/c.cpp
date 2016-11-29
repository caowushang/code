/* ***********************************************
Author        :caowushang
Created Time  :2016年10月09日 星期日 21时05分38秒
File Name     :c.cpp
************************************************ */

#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
const int maxn=1e6+10;
int n,m,k;
struct point
{
	int x,y;
	int p;
	int z,f;
	point(int x=0,int y=0,int p=0):x(x),y(y),p(p)
	{
		z=y-x+(maxn>>1);
		f=y+x;
	}
	bool operator <(const point&a)const
	{
		if(x==a.x)
			return y<a.y;
		return x<a.x;
	}
	bool operator ==(const point&a)const
	{
		return !(a<*this)&&!(*this<a);
	}
	bool out()
	{
		return (x==0&&y==m)||(x==n&&y==0)||(x==n&&y==m);
	}
};
vector<point> Z[maxn];
vector<point> F[maxn];
ll ans[maxn];
ll dd;
set<point> S;
vector<point>& nextpoint(point& go,point &ne)
{
	point x=(go==F[go.f][0])?F[go.f][1]:F[go.f][0];
	point y=(go==Z[go.z][0])?Z[go.z][1]:Z[go.z][0];
	if(S.find(x)==S.end()&&F[go.f].size()>1)
	{
		ne=x;
		return F[go.f];
	}
	else
	{
		ne=y;
		return Z[go.z];
	}
}
ll cal(point&a,point&b)
{
	return abs(a.x-b.x);
}
point run(point& go)
{
	S.insert(go);
	point ne;
	vector<point> &l=nextpoint(go,ne);
	for(int i=2;i<l.size();i++)
	{
		if(ans[l[i].p]==-1)
			ans[l[i].p]=dd+cal(l[i],go);
	}
	dd+=cal(go,ne);
	return ne;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	memset(ans,-1,sizeof(ans));
	dd=0;
    scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=n;i++)
	{
		point x(i,0,0);
		point y(i,m,0);
		Z[x.z].pb(x),Z[y.z].pb(y);
		F[x.f].pb(x),F[y.f].pb(y);
	}
	cout << endl;
	for(int i=1;i<m;i++)
	{
		point x(0,i,0);
		point y(n,i,0);
		Z[x.z].pb(x),Z[y.z].pb(y);
		F[x.f].pb(x),F[y.f].pb(y);
	}
	for(int i=1;i<=k;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		point a(x,y,i);
		Z[a.z].pb(a),F[a.f].pb(a);
	}
	point go(0,0);
	while(!go.out())go=run(go);
	for(int i=1;i<=k;i++)
		printf("%I64d\n",ans[i]);
    return 0;
}
