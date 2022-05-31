#include<bits/stdc++.h>
using namespace std;



bool dfs(int src, int par, int color, vector<int> &colored,
         vector<int> adj[])
{
    colored[src] = color;
//1-color se swich krta rhega 0 - 1 - 0
    for (auto x : adj[src])
    {
        if (colored[x] == -1)
        {
            if(!dfs(x, src, 1 - color, colored, adj))
            {
                return false;
            }
        }
        else if (colored[x] == color)
        {
           return false;
        }
    }
return true;
   
}

bool isBipartite(int V, vector<int> adj[])
{
    vector<int> colored(V, -1);
    // color -  0 / 1
   
    for (int i = 0; i < V; i++)
    {
        if (colored[i] == -1)
        {
            if(!dfs(i, -1, 0, colored, adj)) 
               {return false;}
        }
    }

    return true;
}