#include"bits/stdc++.h"
using namespace std;

/*
Dijkstra's algorithm allows us to find the shortest path between any two vertices of a graph.
It differs from the minimum spanning tree because the shortest distance between two vertices 
might not include all the vertices of the graph.
*/
void dij(vector<vector<pair<int,int>>> &graph,vector<int> &vis,vector<int> &dis){
	// Creating a min heap to sort according to max dis first
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	// distance from 1 to 1 is 0
	dis[1]=0; 
	pq.push({0,1});
	while(!pq.empty()){
		int prev=pq.top().second;
		vis[prev]=1;
		pq.pop();
		for(auto it:graph[prev]){
			int nxt=it.first;
			int cost=it.second;
			// relaxing node (if nxt node dis is greater than current dis and nxt weight)
			if(!vis[nxt] && cost+dis[prev]<dis[nxt]){
				dis[nxt]=cost+dis[prev];
				pq.push({dis[nxt],nxt});
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.out","w",stdout);
	#endif
	int v,e;
	cin>>v>>e;
	vector<vector<pair<int,int>>> graph(v+1);
	for(int i=0;i<e;i++){
		int x,y,w;
		cin>>x>>y>>w;
		graph[x].push_back({y,w});
		graph[y].push_back({x,w});
	}
	vector<int> vis(v+1,0);
	vector<int> dis(v+1,INT_MAX);
	dij(graph,vis,dis);
	for(int i=1;i<dis.size();i++)cout<<dis[i]<<" ";
}
