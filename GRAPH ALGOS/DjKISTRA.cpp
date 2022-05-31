#include <bits/stdc++.h>
using namespace std;

main()
{
    int V = 5;

    vector<pair<int, int>> g[V + 1];
    int srcnode = 1;

    // graph
    //  g[node].push_back({adjacentnode , weigth})
    // pair{node , edge dist or weight}
    g[1].push_back({2, 2});
    g[1].push_back({4, 1});
    g[2].push_back({1, 2});
    g[2].push_back({5, 5});
    g[2].push_back({3, 4});
    g[3].push_back({2, 4});
    g[3].push_back({4, 3});
    g[3].push_back({5, 1});
    g[4].push_back({1, 1});
    g[4].push_back({3, 3});
    g[5].push_back({2, 5});
    g[5].push_back({3, 1});

    // min heap to give min dist node every time
    //  nearest node to a curr node
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // ALL MIN  DISTANCES INITIALLY INFINITY
    vector<int> mindist(V + 1, INT_MAX);
    mindist[srcnode] = 0;
    // (  curr marked distance from source,node val )
    pq.push({0, srcnode});

    while (!pq.empty())
    {
        int node = pq.top().second;
        int dismark = pq.top().first;
        pq.pop();
        for (auto x : g[node])
        {
            int ngbnode = x.first; //node
            int edgewgt = x.second;//mrked

            if(mindist[ngbnode] > dismark + edgewgt)
            {
                mindist[ngbnode] = dismark + edgewgt;
                pq.push({mindist[ngbnode] ,ngbnode });
            }
        }

    }




cout<<"\n DKISTRA ALGO\n";
cout<<"\n source: "<<srcnode;
cout<<endl;
    for(int i = 1 ; i <=V; i++)
    {
        cout<<i<<" at dist :"<<mindist[i];
        cout<<endl;
    }
}