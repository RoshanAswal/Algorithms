#include"bits/stdc++.h"
using namespace std;

/*
The Kosaraju algorithm is a DFS based algorithm used to find Strongly Connected Components(SCC)
in a graph. It is based on the idea that if one is able to reach a vertex v starting from vertex u,
then one should be able to reach vertex u starting from vertex v and if such is the case, one can 
say that vertices u and v are strongly connected - they are in a strongly connected sub-graph.
*/

void dfs(vector<vector<int>> &graph,int i,stack<int> &st,vector<int> &vis){
	if(vis[i])return;
	vis[i]=1;
	for(int j:graph[i]){
		if(!vis[j])dfs(graph,j,st,vis);
	}
	st.push(i);
}

void revdfs(vector<vector<int>> &graph,int i,vector<int> &vis){
	if(vis[i])return;
	vis[i]=1;
	for(int j:graph[i]){
		if(!vis[j])revdfs(graph,j,vis);
	}
	cout<<i<<" ";
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
	
	// Making directed graph
	vector<vector<int>> graph(v+1);
	
	for(int i=0;i<e;i++){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
	}

	// Taking a visited vector and
	// stack which will store elements according to finish time in dfs of every element
	// This can be done using topological sort
	vector<int> vis(v+1,0);
	stack<int> st;
	for(int i=1;i<v;i++){
		if(!vis[i])
			dfs(graph,i,st,vis);
	}
	// reversing the graph i.e if we have edge 1->2 now it will be from 2->1
	vector<vector<int>> newgraph(v+1);
	for(int i=1;i<=v;i++){
		for(int j:graph[i])
			newgraph[j].push_back(i);
	}

	fill(vis.begin(),vis.end(),0);
	
	// Again performing dfs, this time on new graph
	// When a node reaches all it's adjacent node in bfs then it is one SSC(Strongly connected graph)
	while(!st.empty()){
		int n=st.top();
		st.pop();
		revdfs(newgraph,n,vis);
		cout<<endl;
	}
}
