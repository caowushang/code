/*************************************************************************
	> File Name: b.cpp
	> Author: caowushang
	> Mail: 15630929347@163.com 
	> Created Time: 2016年10月09日 星期日 14时58分45秒
 ************************************************************************/

#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector<vector<int> > a;
vector<vector<int> > b;
vector<vector<int> > c;
int n,m;
int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		a.pb(vector<int>());
		for(int j=0;j<m;j++)
		{
			int x;
			cin>>x;
			a[i].pb(x);
		}
	}
	c=a;
	for(int i=0;i<n;i++)
		sort(c[i].begin(),c[i].end());
	bool f=0;
	for(int i=0;i<m;i++)
	{
		if(!f)
		for(int j=i;j<m;j++)
		{
			b=a;
			for(int k=0;k<n;k++)
				swap(b[k][i],b[k][j]);
			bool ff=0;
			for(int k=0;k<n;k++)
			{
				if(ff) break;
				int cnt=0;
				for(int l=0;l<m;l++)
					if(b[k][l]!=c[k][l])
						cnt++;
				if(cnt>2)
					ff=1;
			}
			if(!ff)
				f=1;
		}
	}
	if(f)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
