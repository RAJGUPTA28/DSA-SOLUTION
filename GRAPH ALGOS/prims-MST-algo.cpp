#include <bits/stdc++.h>
using namespace std;

// prims algo
//  give mst of the tree

// approach
//  weight array of that indx
//  inmst bool array to keep tracK of node INCLUDED in mst or not
// parent node to keep track of the parent of that index node

main()
{
    int V = 5;
    vector<pair<int, int>> adj[V];

    // ADJ[NODE].PUSH_BACK({ADJACNET NODE , WEIGHT})
    int src = 0;
    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[1].push_back({4, 5});
    adj[2].push_back({1, 3});
    adj[2].push_back({4, 7});
    adj[3].push_back({0, 6});
    adj[3].push_back({1, 8});
    adj[4].push_back({1, 5});
    adj[4].push_back({2, 7});

    // min heap
    // it gives min dist node to a node
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    //(edgeweight , node)

    // source node se chalu kro

    vector<bool> inMST(V, false);   // NODE IN MST
    vector<int> weight(V, INT_MAX); // WGT B/W PARENT TO IT
    vector<int> parent(V,-1);

    parent[src] = -1;
    inMST[src] = true;
    weight[src] = 0;

    // weignt , source node
    pq.push({0, src});

    while (!pq.empty())
    {
        int par = pq.top().second;
        pq.pop();
        inMST[par] = true;
        for (auto x : adj[par])
        {
            int ngbnode = x.first;
            int edgewgt = x.second;
            if (inMST[ngbnode]==false && edgewgt < weight[ngbnode])
            {
                weight[ngbnode] = edgewgt;
                parent[ngbnode] = par;
                pq.push({edgewgt, ngbnode});
            }
        }
    }

    
    cout <<"\n - PRIMS ALGO -" <<endl;
    cout<<"\n source is : "<<src;
    int wght =0;
    for (int i = 0; i < V; i++)
    { 
        cout << endl;
        wght+=weight[i];
        cout << i << " parent is " << parent[i] << "-> weight : " << weight[i];
    }
    cout<<"\nThe min cost is : "<<wght;
}