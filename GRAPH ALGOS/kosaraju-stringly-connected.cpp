#include <bits/stdc++.h>
using namespace std;

//KOSA RAJU ALGO

// dirctd graph
//  make a reverse directed  graph of the curr graph
// make a order vector and store all the valeus from back stack of dfs traversal of teh graph
// now traverse from last of the order vector in reverse dfs and runn a dfs the number the tie the dfs will run is the no. of strongly connected component

 void dfs(int src, vector<int> &visited, vector<int> &order, vector<int> grp[])
{
    visited[src] = 1;
    for (auto x : grp[src])
    {
        if (!visited[x])
        {
            dfs(x, visited, order, grp);
        }
    }
    // push val of nodes while back tracking
    order.push_back(src);
}

void rdfs(int src, vector<int> &visited, vector<int> rgrp[])
{
    visited[src] = 1;
    for (auto x : rgrp[src])
    {
        if (!visited[x])
        {
            rdfs(x, visited, rgrp);
        }
    }
}

int kosaraju(int V, vector<int> grp[])
{
    vector<int> order;

    vector<int> visited(V, 0);

    vector<int> Rgrp[V]; // reverse graph

    for (int i = 0; i < V; i++)
    {
        for (auto x : grp[i])
        {
            Rgrp[x].push_back(i);
        }
    }
    

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, order, grp);
        }
    }


        vector<int> visited1(V, 0);

    int count = 0;
    for (int i = V - 1; i >= 0; i--)
    {
        if (!visited1[order[i]])
        {   count++;
            rdfs(order[i], visited1, Rgrp);
            
        }
    }

    return count;
}


