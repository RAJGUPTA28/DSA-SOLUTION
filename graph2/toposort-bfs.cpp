	
    #include<bits/stdc++.h>
    using namespace  std;
   
    //bfs

    // indegree yaani kitne aarow aa re h uspe
    
    vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   vector<int> indegree(V,0);
	   vector<int>topo;
	   for(int i = 0 ; i <V ;i++)
	   {
	       for(auto x : adj[i])
	       {indegree[x]++;}
	       
	   }


	   queue<int>q;
	   for(int i = 0 ; i <V ;i++)
	   {if(indegree[i] == 0){
	       
	       q.push(i);}}
	   
	   
	   while(!q.empty())
	   {
	       int temp = q.front();
	       q.pop();
	       topo.push_back(temp);
	       for(auto x : adj[temp])
	       {
	           indegree[x]--;
	           if(indegree[x] == 0)
	           {q.push(x);}
	       }
	       
	   }
	   return topo;
	   
	   
	}