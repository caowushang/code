/*************************************************************************
  > File Name: a.cpp
  > Author: caowushang
  > Mail: 15630929347@163.com 
  > Created Time: 2016年10月02日 星期日 12时17分42秒
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{

	int n;
	while(cin >> n)
	{

		double x=sqrt(n);
		if(x>(int)x)
		{
			int b=x;
			while(b)
			{

				int l=b+1;
				int r=n;
				while(l<r)
				{

					int m=(l+r)/2;
					if(m*b<n)
						l=m+1;
					else
						r=m;
					cout << l << " " << r << endl;
				}
				if(l*b==n){
					cout << l*2+b*2 << endl;
					break;
				}
				b--;
			}
		}
		else
			cout << ((int)x)*4 << endl;
	}
	return 0;
}
