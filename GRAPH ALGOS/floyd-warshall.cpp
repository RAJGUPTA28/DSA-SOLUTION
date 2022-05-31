// it gives the min distance b/w any two vertex

// approach  n times pass relaxation
//basically we are tyring all possible way to travel

// for every two nodes check for a node b/w then ad then take min of possible distancez
// similar way take nodes place a 3rd node and check

#include <bits/stdc++.h>
using namespace std;

// o(n3)

const int INF = 1e9;
main()
{
    // nodes

    // bring k node   in i and j

    // adjacency matrix of wgts given
    vector<vector<int>> graph = {{0, 5, INF, 10},
                                 {INF, 0, 3, INF},
                                 {INF, INF, 0, 1},
                                 {INF, INF, INF, 0}};

    int N = graph.size();

    vector<vector<int>> distance = graph;

    for (int k = 0; k < N; k++) // adding node k b/w i and j
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (distance[i][j] > distance[i][k] + distance[k][j])
                {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    cout << "\n THE DISTANCE IS : \n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (distance[i][j] == INF)
            {
                cout << "INF ";
            }
            else
            {
                cout << "   " << distance[i][j];
            }
        }

        cout << endl;
    }

    cout<<"\nshortest distance 2 ,3  : "<<distance[2][3];
}
