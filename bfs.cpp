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
	vector<vector<int>> graph(v+1);
	// for loop till e(edges) 
	for(int i=0;i<e;i++){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		//graph[y].push_back(x); // this is for undirected graph
	}
	queue<int> q;
	q.push(1);
	vector<int> vis(v,0); // visited vector to check which vertex are seen 
	// extra for loop to check disconnected branch also
	for(int i=1;i<v+1;i++){
		if(vis[i])continue;
		while(!q.empty()){
			int n=q.front();
			q.pop();
			for(int i=0;i<graph[n].size();i++){
				if(!vis[graph[n][i]]){
					q.push(graph[n][i]);
					vis[graph[n][i]]=1;
				}
			}
			vis[n]=1;
			cout<<n<<" ";			
		}
	}
}
