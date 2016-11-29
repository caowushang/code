/*************************************************************************
	> File Name: h.cpp
	> Author: caowushang
	> Mail: 15630929347@163.com 
	> Created Time: 2016年10月23日 星期日 17时23分09秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[110];
int a[110];
int vis[110];
int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> s[i];
	bool f=0;
	cin >> a[0];
	vis[a[0]]=1;
	int l=s[a[0]].size();
	for(int i=1;i<m;i++)
	{
		cin >> a[i];
		vis[a[i]]=1;
		if(l!=s[a[i]].size())
			f=1;
	}
	if(f)
		cout << "No" << endl;
	else
	{
		bool fff=0;
		string ans="";
		for(int i=0;i<l;i++)
		{
			bool ff=0;
			char c=s[a[0]][i];
			for(int j=1;j<m;j++)
			{
				if(c!=s[a[j]][i])
				{
					ff=1;
					break;
				}
			}
			if(ff)
				ans+='?';
			else
				ans+=c;
		}
		{
			bool ffff=0;
			for(int i=1;i<=n;i++)
			{
				if(!vis[i])
				{
					if(s[i].size()==l)
					{
						int j;
						for(j=0;j<l;j++)
						{
							if(ans[j]!='?'&&ans[j]!=s[i][j])
								break;
						}
						if(j==l)
							ffff=1;
					}
				}
			}
			if(ffff)
				cout << "No" << endl;
			else
				cout << "Yes" << endl << ans << endl;
		}
	}
	return 0;
}
