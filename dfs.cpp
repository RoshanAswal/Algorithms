#include"bits/stdc++.h"
using namespace std;

void dfs(vector<vector<int>> graph,int ind,vector<int> &vis){
	if(!vis[ind])cout<<ind<<" ";
	vis[ind]=1;
	
	for(int i:graph[ind]){
		if(!vis[i])
			dfs(graph,i,vis);
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
	vector<vector<int>> graph(v+1);
	for(int i=0;i<e;i++){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		// graph[y].push_back(x);
	}
	//using stack
	stack<int> st;
	st.push(1);
	vector<int> vis(v+1,0);
	//for loop for disconnected graph
	for(int i=1;i<=v;i++){
		if(vis[i])continue;
		while(!st.empty()){
			int t=st.top();st.pop();
			if(!vis[t]){
				vis[t]=1;
				cout<<t<<endl;
			}
			for(int i:graph[t]){
				if(!vis[i])st.push(i);
			}
		}
	}

	//Recursive dfs
	for(int i=1;i<=v;i++)
		dfs(graph,i,vis);
}
