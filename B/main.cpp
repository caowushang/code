/*************************************************************************
	> File Name: B.cpp
	> Author: caowushang
	> Mail: 15630929347@163.com
	> Created Time: 2016年10月05日 星期三 11时27分55秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int n,l;
struct ant
{
	int n;
	int x;
	int o;
	int t;
	ant(int xx=0,char cc='L',int nn=0)
	{
		x=xx;
		if(cc=='R')
			o=1,t=l-x;
		else
			o=0,t=x;
		n=nn;
	}
	bool operator < (const ant&k)const
	{
		if(t==k.t)
		{
			if(o==0)
				return 0;
			else
				return 1;
		}
		return t<k.t;
	}
}E[30],O[30];
bool cmp(ant a,ant b)
{
	return a.x<b.x;
}
ant gao(ant N[],int nl)
{
    if(nl==0)
        return ant(0,0,0);
	ant R;
	ant L;
	int rl=0;
	while(N[rl].o!=1&&rl<nl)rl++;
	R=N[rl];
	int ll=nl-1;
	while(N[ll].o!=0&&ll>=0)ll--;
	L=N[ll];
	if(rl==nl)
        return L;
    if(ll==-1)
        return R;
    int tl=0,tr=0;
    for(int i=0;i<nl;i++)
        if(N[i].o==1)
            tr++;
        else
            tl++;
	if(R.t>L.t)
	{
        R.n=N[nl-tr].n;
        return R;
	}
	else
	{
        L.n=N[tl-1].n;
        return L;
	}
}
int main()
{
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
	while(cin >> n >> l && n && l)
	{
		int el=0,ol=0;
		for(int i=0;i<n;i++)
		{
			char l;
			int x;
			cin >> l >> x;
			if(x&1)
				O[ol++]=ant(x,l,i+1);
			else
				E[el++]=ant(x,l,i+1);
		}

		sort(O,O+ol,cmp);
		sort(E,E+el,cmp);
		ant ans=max(gao(O,ol),gao(E,el));
		cout << ans.t << "  " << ans.n << endl;
	}
	return 0;
}
