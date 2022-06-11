#include"bits/stdc++.h"
using namespace std;

/*Tarjan's strongly connected components algorithm is an algorithm in graph theory for finding the strongly connected components of a directed graph. It runs in linear time, matching the time bound for alternative methods including Kosaraju's algorithm and the path-based strong component algorithm. 
*/
void dfs(int i,vector<vector<int>> &graph,vector<int> &disc,vector<int> &low,vector<bool> &instack,stack<int> &st){
	static int time=0; // time taken to reach to a node
	disc[i]=low[i]=time; // if there is no cycle or back node then all will have their there same discovery and
	// accessibliliy time 
	time++;
	instack[i]=true;
	st.push(i);
	for(int j:graph[i]){ // traversin all nodes conneted to parent i
		if(disc[j]==-1){ // if not discovered call dfs on that 
			dfs(j,graph,disc,low,instack,st);
			low[i]=min(low[i],low[j]); // update the parent node accessible time
			// if it is traversing back then of course low will remain same unless some changes
			// occured due to back node we find and updated in else if statement below
		}else if(instack[j]){ // if child vertex discovered and already present in stack then..
			// that must be a back edge which will make that component separate and connected
			// so we need to updata lowest accessible time of parent node comparing with discovery time
			// of child node
			low[i]=min(low[i],disc[j]);
		}
	}
	// if discovery time and lowest accessible time is same for a node then that is head node
	if(disc[i]==low[i]){
		cout<<"here - ";
		while(st.top()!=i){ // print nodes from stack untill find the head node and that will be one 
			// of the strongly connected component
			int num=st.top();
			cout<<num<<" ";
			st.pop();
			instack[num]=false;
		}
		int num=st.top();
		st.pop();
		cout<<num<<endl;
		instack[num]=false;
	}
}

void tarjan(vector<vector<int>> &graph,int v){
	vector<int> disc(v+1,-1); // discovered vector to check if a vertex is discovered/seen or not and when
	vector<int> low(v+1,-1); // It keeps track of lowest time accessible to that vertex like if 1 2 3 
	// are connected then all of them will have 0 time accesiblility because they are strongly conncted
	// and if 2 connected to 4 and 4 is strongly connected to 5 6 then (4,5,6) these all will have 1 as 
	// their lowest time accessibility	
	vector<bool> instack(v+1,false); // to check whether a vertex is present in stack
	stack<int> st;
	for(int i=0;i<=v;i++){
		if(disc[i]==-1) // if not discovered call the dfs for that
			dfs(i,graph,disc,low,instack,st);
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
	// Making graph
	vector<vector<int>> graph(v+1);
	
	for(int i=0;i<e;i++){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y); // It is directed graph
		// graph[y].push_back(x);
	}	
	// calling tarjan to find all strongly connented graph component
	tarjan(graph,v);
}
