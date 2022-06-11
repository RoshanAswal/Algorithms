#include"bits/stdc++.h"
using namespace std;

/*
Bellman Ford algorithm helps us find the shortest path 
from a vertex to all other vertices of a weighted graph.
It is similar to Dijkstra's algorithm but it can work with
graphs in which edges can have negative weights.
Note: we can also detect negative cycle in the graph using Bellmen Ford
*/

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
	vector<vector<pair<int,int>>> graph(v+1);
	
	// Another vector to store edges and their weight
	// to traverse for every pair
	vector<pair<int,pair<int,int>>> p;

	for(int i=0;i<e;i++){
		int x,y,w;
		cin>>x>>y>>w;
		graph[x].push_back({y,w});
		p.push_back({w,{x,y}});
	}

	// Taking a distance vector to store the minimum traversal
	// distance from source node
	
	vector<int> dis(v+1,INT_MAX/2);
	dis[0]=0; //setting staring node's distance = 0
	
	// Traversing for v-1 times i.e (we will try to relax every
	// pair of vertex at most v-1 times) but they can get optimal
	// answer before v-1 traversal
	// NOTE : After v-1 traversal if we traverse one more time 
	// 		  and get new weights that means there is a negative
	//		  cycle in the graph
	for(int i=0;i<v-1;i++){
		for(auto it:p){
			int x=it.second.first; // source node
			int y=it.second.second; // destination node
			int w=it.first; // weight
			if(dis[x]!=INT_MAX && dis[x]+w<dis[y])
				dis[y]=dis[x]+w;
		}
	}

	for(int i=1;i<=v;i++){
		cout<<dis[i]<<" ";
	}
}
