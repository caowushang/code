/* ***********************************************
Author        :caowushang
Created Time  :2016/11/8 13:54:39
TASK		  :dda.cpp
LANG          :C++
Problem		  :
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#define inf 99999999
#define cl(x,v) memset(x,v,sizeof(x))
#define PI 3.14159265358979323
#define LL long long int
using namespace std;
const int MX=1e3+10;
const int mod=1e9+7;
int a[MX];
int b[MX];
vector<int> ans;
int n,k;
struct pp
{
	int l,r;
} q[MX];
bool gao(int l,int r,int ba)
{
	if(l==r)
		return 1;
	int m=a[l],id=l;
	int c;
	for(c=l+1;c<=r;c++)
		if(m!=a[c])break;
	if(c>r)
		return 0;
	for(int i=l+1;i<=r-1;i++)
		if(a[i]>m||(a[i]==m&&(a[i]>a[i+1]||a[i]>a[i-1])))
			m=a[i],id=i;
	if(a[r]>m||(a[r]==m&&a[r]>a[r-1]))
			m=a[r],id=r;
	int ll=id,rr=id;
	int mx=a[id];
	while(ll>l||rr<r)
	{
		if(ll>l&&a[ll-1]<mx)
			mx+=a[ll-1],ans.push_back((-1)*(ba+id-l)),id--,ll--;
		if(rr<r&&a[rr+1]<mx)
			mx+=a[rr+1],ans.push_back((ba+id-l)),rr++;
	}
	return 1;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&k);
	int l=1,cnt=0;
	bool f=1;
	for(int i=1;i<=k;i++)
	{
		int r=l,sum=0;
		scanf("%d",&b[i]);
		if(f){
			while(sum<b[i]&&r<=n)sum+=a[r++];
			if(sum==b[i])q[i].l=l,q[i].r=r-1,l=r,cnt++;
			else if(sum>b[i])f=0;
		}
	}
	if(cnt!=k||l<=n)f=0;
	if(f)
	{
		bool ff=1;
		for(int i=1;i<=k;i++)
			if(ff)
				if(!gao(q[i].l,q[i].r,i))
					ff=0;
		if(ff)
		{
			puts("YES");
			for(int i=0;i<ans.size();i++)
				printf("%d %c\n",abs(ans[i]),ans[i]>0?'R':'L');
		}
		else puts("NO");
	}
	else puts("NO");
    return 0;
}
