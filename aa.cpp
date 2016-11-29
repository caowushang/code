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
			bool f=1;
			int b=x;
			while(f&&b)
			{
				for(int i=b+1;b*i<=n;i++)
					if(b*i==n)
					{
						cout << b*2+i*2 << endl;
						f=0;
					}
				b--;
			}
		}
		else
			cout << ((int)x)*4 << endl;
	}
	return 0;
}
