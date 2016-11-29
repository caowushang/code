/*************************************************************************
	> File Name: c.cpp
	> Author: caowushang
	> Mail: 15630929347@163.com 
	> Created Time: 2016年10月22日 星期六 14时14分50秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int A[5010];
int n;
void gao(int n)
{
	int a=n*3,b=n*3-1,c=n*3-2;
	int x1,x2,x3;
	printf("? %d %d\n",a,b);
	fflush(stdout);
	scanf("%d",&x1);
	printf("? %d %d\n",a,c);
	fflush(stdout);
	scanf("%d",&x2);
	printf("? %d %d\n",c,b);
	fflush(stdout);
	scanf("%d",&x3);
	A[a]=(x1+x2-x3)/2;
	A[b]=x1-A[a];
	A[c]=x2-A[a];
}
int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	scanf("%d",&n);
	int n3=n/3;
	for(int i=1;i<=n3;i++)
		gao(i);
	int xx=n-n3*3;
	for(int i=n3*3+1;i<=n;i++)
	{
		int x;
		printf("? 1 %d\n",i);
		fflush(stdout);
		scanf("%d",&x);
		A[i]=x-A[1];
	}
	printf("! ");
	for(int i=1;i<=n;i++)
		printf("%d ",A[i]);
	puts("");
	return 0;
}
