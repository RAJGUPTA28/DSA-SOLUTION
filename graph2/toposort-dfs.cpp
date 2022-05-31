#include<bits/stdc++.h>
using namespace std;

//jyada se jyada 
// arrow walenodes pehle push krdo 
// sabb pe traverse krne k baad stack m daal do
//dfs

void dfs(int src,vector<int> &visited,stack<int> &st ,vector<int> adj[] )
{
    
    visited[src] = 1;
    for(auto x : adj[src])
    {
        if(!visited[x])
        {dfs(x , visited , st, adj);}
    }
    
    st.push(src);
}



	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>visited(V,0);
	    stack<int> st;
	    vector<int> topo;
	    for(int i = 0 ;i <V;i++ )
	    {
	        if(!visited[i])
	        {
	            dfs(i , visited , st, adj);
	        }
	    }
	   
	   while(!st.empty())
	   {
	       topo.push_back(st.top());
	       st.pop();
	   }
	   return topo;
	   
	}