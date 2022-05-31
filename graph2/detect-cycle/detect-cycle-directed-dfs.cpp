#include<bits/stdc++.h>
using namespace std;

//directed dfs
bool detectcycle(int src , vector<int> &visited , vector<int>&order,
    vector<int> adj[])
    {
        visited[src] = 1;
        order[src] = 1;
        
        for(auto x : adj[src])
        {
            if(!visited[x])
            {
                bool f = detectcycle(x , visited , order , adj);
                if(f){return true;}
            }
            else if(order[x] == 1)// visited h prr firr bhi kissi k adj m h  mtlb cycle h 
            {return true;}
        }
        // back track 
        order[src]=0 ; 
        return false;
        
        
    }
    
    
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V,0) ; 
        vector<int>order(V,0);
        for(int i = 0 ; i < V ;i++)
        {
            if(!visited[i])
            {
             bool f =  detectcycle(i , visited ,order , adj );
             if(f){return true;}
            }
        }
       
       return false;
    }