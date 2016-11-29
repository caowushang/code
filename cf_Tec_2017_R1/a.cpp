/* ***********************************************
Author        :caowushang
Created Time  :2016年10月20日 星期四 14时06分10秒
File Name     :a.cpp
************************************************ */

#include <bits/stdc++.h>
#define pb push_back
#define pop pop_back
using namespace std;
vector<int> ans;
int s,e;
bool f=0;
bool dfs(int s)
{
	ans.pb(s);
	if(s==e)
		return 1;
	else if(s>e)
		return 0;
	if(f)
		if(dfs(s*10+1))
			return 1;
		else
			ans.pop();
	if(dfs(s*2))
		return 1;
	else
		ans.pop();
	return 0;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d",&s,&e);
	int x=e%10;
	if(x==1||x==2||x==4||x==6||x==8)
		f=1;
	if(dfs(s))
	{
		printf("YES\n%d\n",ans.size());
		for(int i=0;i<ans.size();i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
	else
		puts("NO");
    return 0;
}
