#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int maxn=1e6+10;
struct Edge{
	int from,to;
	ll dist;
};
struct HeapNode{
	int d,u;
	bool operator <(const HeapNode& rhs)const {
			return d>rhs.d;
			}
};
struct Dijkstra {
	int n;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool done[maxn];
	ll d[maxn];
	ll p[maxn];
	void init(int n){
		this->n=n;
			for(int i=0;i<n;i++)G[i].clear();
			edges.clear();
		}
	void AddEdge (int from,int to,ll dist) {
			edges.push_back((Edge){from,to,dist});
			int m=edges.size();
			G[from].push_back(m-1);
		}
	void dijkstra(int s){
			priority_queue<HeapNode> Q;
			for(int i=0;i<n;i++)d[i]=INF;
			d[s]=0;
			memset(done,0,sizeof(done));
			Q.push((HeapNode){0,s});
			while(!Q.empty()){
						HeapNode x=Q.top();Q.pop();
						int u=x.u;
						if(done[u])continue;
						done[u]=true;
						for(int i=0;i<G[u].size();i++){
										Edge& e=edges[G[u][i]];
										if(d[e.to]>d[u]+e.dist){
															d[e.to]=d[u]+e.dist;
															p[e.to]=G[u][i];
															Q.push((HeapNode){d[e.to],e.to});
														}
									}
					}
		}
}dij;
struct pp
{
	ll t;
	int p;
	bool operator <(const pp& a)const
	{
		if(t==a.t)
			return p<a.p;
		return t<a.t;
	}
}ans[maxn];
int main()
{
	int t;
	int n,m;
	scanf("%d",&t);
	for(int ii=1;ii<=t;ii++)
	{
		scanf("%d%d",&n,&m);
		dij.init(n+m+1);
		int cnt=n;
		for(int i=0;i<m;i++)
		{
			int t,s,x;
			cnt++;
			scanf("%d%d",&t,&s);
			for(int j=0;j<s;j++)
			{
				scanf("%d",&x);
				dij.AddEdge(cnt,x,t);
				dij.AddEdge(x,cnt,t);
			}
		}
		dij.dijkstra(1);
		for(int i=1;i<=n;i++)
		{
			ans[i].p=i;
			ans[i].t=dij.d[i];
		}
		dij.dijkstra(n);
		for(int i=1;i<=n;i++)
			ans[i].t=max(ans[i].t,dij.d[i]);
		sort(ans+1,ans+n+1);
		printf("Case #%d: ",ii);
		if(ans[1].t!=INF)
		{
			int ss=1;
			while(ans[ss].t==ans[1].t)ss++;
			printf("%lld\n",ans[1].t/2);
			for(int i=1;i<ss;i++){
				printf("%d",ans[i].p);
				if(i<ss-1)
					printf(" ");
			}
			printf("\n");
		}
		else
			printf("Evil John\n");
	}
	return 0;
}

