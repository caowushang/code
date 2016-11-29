/*************************************************************************
	> File Name: code/cf373/b.cpp
	> Author: caowushang
	> Mail: 15630929347@163.com 
	> Created Time: 2016年09月28日 星期三 17时17分47秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	int r1=0,b1=0,r2=0,b2=0;
	int n;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		char x;
		scanf("%c",&x);
		if(n&1)
			x=='r'?r1++:b1++;
		else
			x=='r'?r2++:b2++;
	}
//	cout << r1 << " " << b1 << " " << r2 << " " << b2 << endl;
	int a=b1+abs(b1-r2);
	int b=r1+abs(r1-b2);
	int c=b2+abs(b2-r1);
	int d=r2+abs(r2-b1);
//	cout << a << " " << b << " " << c << " " << d << endl;
	int ans=min(a,min(b,min(c,d)));
	cout << ans << endl;
	return 0;
}
