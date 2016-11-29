#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<ctype.h>
#include<math.h>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<bitset>
#include<algorithm>
#include<time.h>
using namespace std;
const int N=100005;
int T,n;
int a[N];
int S[N];
int J[N];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        memset(S,0,sizeof(N));
        memset(J,0,sizeof(J));
        int sh=1,ja=1;
        scanf("%d",&a[1]);
        S[1]=1;
        J[1]=1;
        for(int i=2;i<=n;i++)
        {
            scanf("%d",&a[i]);
            for(int j=i-1;j>=1&&j>=i-3;j--)
            {
                S[i]=1,J[i]=1;
                if(a[i]>=a[j])
                    S[i]=max(S[i],S[j]+1);
                if(a[i]<=a[j])
                    J[i]=max(J[i],J[j]+1);
                sh=max(sh,S[i]);
                ja=max(ja,J[i]);
            }
        }
       // cout << sh << " " << ja << endl;
    //    for(int i=1;i<=n;i++)
    //        cout << S[i] << " ";
     //   cout << endl;
        if(sh>=n-1||ja>=n-1)
            puts("YES");
        else
            puts("NO");
    }

    return 0;
}
