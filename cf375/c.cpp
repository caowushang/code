/*************************************************************************
	> File Name: c.cpp
	> Author: caowushang
	> Mail: 15630929347@163.com 
	> Created Time: 2016年10月04日 星期二 13时26分49秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2100];
int b[2100];
int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i]<=m)
			b[a[i]]++;
	}
	int mx=n/m;
	int mis=0;
	queue<int> q;
	for(int i=1;i<=m;i++)
	{
		if(b[i]<mx)
		{
			int x=mx-b[i];
			mis+=x;
			while(x--) q.push(i);
		}
	}
	for(int i=0;i<n;i++)
	{
			if(a[i]>m)
			{
				if(!q.empty())
				{
					int x=q.front();
					q.pop();
					a[i]=x;
					b[x]++;
				}
			}
	}
	for(int i=0;i<n;i++)
	{
		if(!q.empty())
		{
			if(b[a[i]]>mx)
			{
				int x=q.front();
				q.pop();
				b[a[i]]--;
				b[x]++;
				a[i]=x;
			}
		}
	}
	cout << mx << " " << mis << endl;
	for(int i=0;i<n;i++)
		cout << a[i] << " ";
	return 0;
}
