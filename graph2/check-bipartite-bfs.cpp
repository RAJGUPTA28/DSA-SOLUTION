#include <bits/stdc++.h>
using namespace std;
//same as dfs but now use queue
bool bfs(int src, vector<int> &coloured, vector<int> adj[])
{
    queue<int> q;
    q.push(src);
    coloured[src] = 1;
    while (!q.empty())
    {
        int par = q.front();

        q.pop();
        for (auto x : adj[par])
        {
            if (coloured[x] == -1)
            {
                coloured[x] = 1 - coloured[par];
                q.push(x);
            }
            else if (coloured[x] == coloured[par])
            {
                return false;
            }
        }
    }

    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    vector<int> coloured(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (coloured[i] == -1)
        {
            if (!bfs(i, coloured, adj))
            {
                return false;
            }
        }
    }
    return true;
}