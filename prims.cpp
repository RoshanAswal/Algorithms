#include"bits/stdc++.h"
using namespace std;

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
	vector<vector<pair<int,int>>> graph(v+1);
	for(int i=0;i<e;i++){
		int x,y,w;
		cin>>x>>y>>w;
		graph[x].push_back({y,w});
		graph[y].push_back({x,w});
	}
	// three vectors
	// wt to store the optimal weight for each vertex
	// mst to check whether the vetex is included in graph or not
	// pat to assign the parent to the node ( there can be only one because there are no cylces in MST)
	vector<int> wt(v),mst(v),par(v);
	for(int &i:wt)i=INT_MAX;
	for(int &i:mst)i=0;
	for(int &i:par)i=-1;
	mst[0]=1;wt[0]=0;
	// Loop starting from 1 because we are taking starting vertex as 0 which will
	// have 0 wight and no parent
	for(int i=1;i<v;i++){
		int node=0,p=0,min_wt=INT_MAX;
		for(int j=0;j<v;j++){
			// only checking the vertex which are already in MST and traversing their adjacent nodes
			if(mst[j]==1){
				for(auto k:graph[j]){
					// if not in MST and then check their weight to find minimum
					if(mst[k.first]==0 && k.second<min_wt){
						min_wt=k.second;
						node=k.first;
						p=j;
					}
				}
			}
		}
		// including vertex in MST, setting minimum weight and parent
		mst[node]=1;
		wt[node]=min_wt;
		par[node]=p;
	}
	// Making new graph
	vector<vector<pair<int,int>>> newgraph(v+1);
	for(int i=1;i<par.size();i++){
		newgraph[par[i]].push_back({i,wt[i]});
	}
	for(int i=0;i<newgraph.size();i++){
		cout<<i<<"-> ";
		for(auto it:newgraph[i]){
			cout<<it.first<<" "<<it.second<<endl;
		}
	}
}
