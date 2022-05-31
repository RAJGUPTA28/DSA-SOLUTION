#include<bits/stdc++.h>
using namespace std;

// kisi node ko uske parent k illaw a koi aur  
//visit maar ra h toh cycle h 

//kisi aur k neighbour



//undirected   dfs

bool detectcycle(int src , int parent ,vector<int> &visited ,
   vector<int>adj[] )
   {
       visited[src]  =1 ;
       
       for(auto x : adj[src])
       {
           if(!visited[x])
           {
               int f =  detectcycle(x , src , visited , adj);
               if(f){return true;}
           }
           else if(x!=parent){return true;} // parent n pehle mark kia hota h usse 
       }
       
       return false;
   }
   
   
    
    bool isCycle(int V, vector<int> adj[]) 
    {
        vector<int> visited(V , 0);
        
        for(int i = 0 ; i<V ; i++)
        {
          if(!visited[i])
          {
              int f = detectcycle(i , -1, visited , adj);
               if(f){return true;}
          }
        }
      return false;
    }