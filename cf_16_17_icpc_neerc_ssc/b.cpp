/*************************************************************************
	> File Name: b.cpp
	> Author: caowushang
	> Mail: 15630929347@163.com 
	> Created Time: 2016年10月23日 星期日 18时55分47秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int mp[55][55];
int mm[55];
int n;
map<char,int> ys;
int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	ys['=']=0;
	ys['<']=1;
	ys['>']=2;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(mp,-1,sizeof(mp));
		memset(mm,0,sizeof(mm));
		scanf("%d",&n);
		int m=n;
		for(int i=1;i<=n;i++)
			mm[i]=i;
		int l;
		while(1)
		{
			if(m==1)
			{
				l=mm[1];
				break;
			}
			int ml=m/2;
			for(int i=1;i<=ml;i++)
			{
				int b=mm[i*2],a=mm[i*2-1];
				mm[i]=a;
				if(mp[a][b]==-1)
				{
					printf("? %d %d\n",a,b);
					fflush(stdout);
					char c;
					cin >> c;
					mp[a][b]=ys[c];
				}
				if(mp[a][b]==2)
					mm[i]=b;
			}
			if(m&1)
			{
				mm[ml+1]=mm[m];
				m=ml+1;
			}
			else
				m=ml;	
		}
		m=n;
		for(int i=1;i<=n;i++)
			mm[i]=i;
		int r;
		while(1)
		{
			if(m==1)
			{
				r=mm[1];
				break;
			}
			int ml=m/2;
			for(int i=1;i<=ml;i++)
			{
				int b=mm[i*2],a=mm[i*2-1];
				mm[i]=a;
				if(mp[a][b]==-1)
				{
					printf("? %d %d\n",a,b);
					fflush(stdout);
					char c;
					cin >> c;
					mp[a][b]=ys[c];
				}
				if(mp[a][b]==1)
					mm[i]=b;
			}
			if(m&1)
			{
				mm[ml+1]=mm[m];
				m=ml+1;
			}
			else
				m=ml;
		}
		printf("! %d %d\n",l,r);
		fflush(stdout);
	}
	return 0;
}
