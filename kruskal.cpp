#include"bits/stdc++.h"
using namespace std;
//Kruskal's Algorithm is used to find the minimum spanning tree for a connected weighted graph. The main target of the algorithm is to find the subset of edges by using which we can traverse every vertex of the graph. It follows the greedy approach that finds an optimum solution at every stage instead of focusing on a global optimum.

// DSU ( to find whether two vertix have same parent ) (if not getting try make a small graph)
int find(int x,vector<int> &p){
	if(p[x]==-1)return x;
	return find(p[x],p);
}
// just extra function
bool same(int x,int y,vector<int> &p){
	return find(x,p)==find(y,p);
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
	// Making graph
	vector<vector<pair<int,int>>> graph(v+100);
	// storing {v,w} with weights of the edges
	vector<pair<int,pair<int,int>>> temp;
	// storing the parents to find connected components later [-1,-1,-1,-1] which will
	// help to find minimum edges joining two vertex which are not joined yet
	vector<int> par(v+100,-1);
	for(int i=0;i<e;i++){
		int x,y,w;
		cin>>x>>y>>w;
		graph[x].push_back({y,w});
		graph[y].push_back({x,w});
		temp.push_back({w,{x,y}});
	}
	// sorting to get smallest at front and can greedily choosen
	sort(temp.begin(),temp.end());
	for(int i=0;i<temp.size();i++){
		int x=temp[i].second.first;
		int y=temp[i].second.second;
		//checking if two vertex are of same component so that they not make cycle
		if(!same(x,y,par))
			par[x]=y;
		else
			temp[i].first=INT_MIN;
	}

	// // Making new graph
	vector<vector<pair<int,int>>> newgraph(v+1);
	for(int i=0;i<temp.size();i++){
		if(temp[i].first!=INT_MIN){
			int x=temp[i].second.first;
			int y=temp[i].second.second;
			int w=temp[i].first;
			newgraph[x].push_back({y,w});
		}
	}
	for(int i=0;i<newgraph.size();i++){
		cout<<i<<"-> ";
		for(auto it:newgraph[i]){
			cout<<it.first<<" ";
		}
		cout<<endl;
	}
}
