#include"bits/stdc++.h"
using namespace std;

/*
The Floyd Warshall Algorithm is for solving the All Pairs
Shortest Path problem.
The problem is to find shortest distances between every pair of 
vertices in a given edge weighted directed Graph.
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
	// Storing shortest path from every source to every other source in dp matrix
	vector<vector<int>> dp(v+1,vector<int>(v+1,INT_MAX/2));
	// Making directed graph NOtE : it can also work on undirected graph
	vector<vector<pair<int,int>>> graph(v+1);
	for(int i=0;i<e;i++){
		int x,y,w;
		cin>>x>>y>>w;
		graph[x].push_back({y,w});
		dp[x][y]=w;
	}
	// initializing diagonals with 0 and rest with inf because (1,1) has 0
	// distance to travel
	for(int i=1;i<=v;i++)
		dp[i][i]=0;
	// using k as the intermediate vertex to find distance between
	// two vertices eg. if there are no edge between 1 and 4 then
	// there can be path from 1->3->4 here 3 work as intermediate
	// vertex and this work is done for every other vertex
	for(int k=1;k<=v;k++){
		for(int i=1;i<=v;i++){
			for(int j=1;j<=v;j++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
		}
	}
	// complexity - O(n^3)
	for(int i=1;i<=v;i++){
		for(int j=1;j<=v;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
}
