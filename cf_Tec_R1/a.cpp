/*************************************************************************
	> File Name: a.cpp
	> Author: caowushang
	> Mail: 15630929347@163.com 
	> Created Time: 2016年10月20日 星期四 17时50分13秒
 ************************************************************************/
#pragma comment(linker,"/STACK:1024000000,1024000000")
#include<bits/stdc++.h>
using namespace std;
int s,e;
int a[100];
int l=0;
bool f=0;
bool dfs(int e)
{
	a[l++]=e;
	if(e==s)
		return true;
	else if(e<s)
		return false;
	if(e&1)
	{
		if(e%10==1)
			return dfs(e/10);
		else
			return false;
	}
	else
		return dfs(e/2);
}
int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	scanf("%d%d",&s,&e);
	if(dfs(e))
	{
		printf("YES\n%d\n",l);
		for(int i=l-1;i>=0;i--)
			printf("%d ",a[i]);
		puts("");
	}
	else
		puts("NO");
	return 0;
}
