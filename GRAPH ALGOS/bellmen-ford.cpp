// min distance from src to all nodes

// its handles the negative weight s also that dksitra cannot handle

#include <bits/stdc++.h>
using namespace std;

struct node
{
public:
    int nd1;
    int nd2;
    int edgwt;
    node(int n1, int n2, int eedgwt)
    {
        nd1 = n1;
        nd2 = n2;
        edgwt = eedgwt;
    }
};

main()
{

    int N = 6;   // node
    int edg = 7; // edge
    vector<node> edges;

    // node1 node2  distance
    edges.push_back(node(0, 1, 5));
    edges.push_back(node(1, 2, -2));
    edges.push_back(node(1, 5, -3));
    edges.push_back(node(2, 4, 3));
    edges.push_back(node(3, 2, 6));
    edges.push_back(node(3, 4, -2));
    edges.push_back(node(5, 3, 1));

    int src = 0;
    int inf = 10000000;
    vector<int> dist(N, inf);
    dist[src] = 0;

    // n-1 passes n nodes

    // apply the concept like dkistra for allnodes until n -1 passed till the time the distance values doesnt change

    for (int i = 1; i <= N - 1; i++)
    {
        for (auto e : edges)
        { // setting node 2 distance using node 1
            if (dist[e.nd2] > dist[e.nd1] + e.edgwt)
            {
                dist[e.nd2] = dist[e.nd1] + e.edgwt;
            }
        }
    }




    // trying a last check pass
    // verifying step ki iss the distance still changing or  not if yess no ans exist else  nice

    bool f = 1;
    for (auto e : edges)
    {
        if (dist[e.nd2] > dist[e.nd1] + e.edgwt)
        { // if m aaya  still value changeing
            f = 0;
            break;
        }
    }

    // print
    if (f)
    {
        cout << "\nsrc : " << src << endl;
        for (int i = 0; i < N; i++)
        {
            cout << endl;
            cout << i << " ->  " << dist[i];
        }
    }

    else
    {
        cout << "no ans exist values keep on changing";
    }
}