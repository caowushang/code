/*************************************************************************
    > File Name: Dijkstra.cpp
    > Author: caowushang
    > Mail: 15630929347@163.com 
    > Created Time: 2016年10月08日 星期六 23时02分16秒
 ************************************************************************/

#include<bits/stdc++.h>
const int maxn=1e6+10;
const int INF=0x3f3f;
using namespace std;
struct Edge{
	int from,to,dist;
};
struct HeapNode{
	int d,u;
	bool operator <(const HeapNode& rhs)const {
		return d>rhs.d;
	}
};
struct Dijkstra {
	int n,m;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool done[maxn];
	int d[maxn];
	int p[maxn];
	void init(int n) {
		this->n=n;
		for(int i=0;i<n;i++)G[i].clear();
		edges.clear();
	}
	void AddEdge (int from,int to,int dist) {
		edges.push_back((Edge){from,to,dist});
		m=edges.size();
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
};
int main()
{
	return 0;
}
