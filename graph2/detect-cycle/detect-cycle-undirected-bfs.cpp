#include<bits/stdc++.h>
using namespace std;

// same as dfs but 
// use queue


 bool detectcycle(int src , vector<int>&visited ,vector<int> adj[])
   {
       
       
       queue<pair<int , int>> q;
       
       q.push({src , -1});
       visited[src] = 1;
       
       while(!q.empty())
       {
           int curr = q.front().first;
           int par = q.front().second;
           q.pop();
           for(auto x : adj[curr])
          {
              if(!visited[x])
              {
                  visited[x] = 1;
                  q.push({x , curr});
                  
              }
              else if(x != par){return true;}
          }
           
       }
       
       return false;
   }
   
   
   
    bool isCycle(int V, vector<int> adj[]) {
      
      vector<int>visited(V,0);
      for(int i = 0 ; i <V;i++)
      {
          if(!visited[i])
          {
              int f = detectcycle(i ,visited,adj);
              if(f)return true;
          }
          
      }
      
      return false;
      
    }