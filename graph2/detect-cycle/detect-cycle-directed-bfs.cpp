#include<bits/stdc++.h>
using namespace std;   
   //directed
   // there would a node left out with indegree as non zero even after removing 
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);//kitne arrows h apne pe 
        
       for(int i = 0 ; i <V;i++)
       {
           for(auto x : adj[i])
             {indegree[x]++;}
       }
       
       // store values acc to 0 indegree
      queue<int> q;
      int c = 0; 
      
      for(int i = 0 ; i <V ; i++)
      {
          if(indegree[i] == 0)
          {
          q.push(i);
              c++;
          }
      }
      
      
      while(!q.empty())
      {
          int temp = q.front();
          q.pop();
          for(auto x : adj[temp])
          { 
              indegree[x]--;
              if(indegree[x] == 0)
              { q.push(x);
                  c++;
              }
          }
          
      }
      
      if(c==V){return false;}
      else{return true;}
      
    }