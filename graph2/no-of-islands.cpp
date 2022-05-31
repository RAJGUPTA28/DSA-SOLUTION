#include <bits/stdc++.h>

using namespace std;

// aatho direction m chalaao
void dfs(int i,int j,vector<vector<bool>> &vis,vector<vector<char>> &grid,int n,int m)
   {
       if(i<0 or j<0 or i>=n or j>=m)  return;
       if(grid[i][j]=='0') return;
       
       if(vis[i][j]!=true)
       {
           vis[i][j]=true;
           dfs(i+1,j,vis,grid,n,m);
           dfs(i-1,j,vis,grid,n,m);
           dfs(i,j+1,vis,grid,n,m);
           dfs(i,j-1,vis,grid,n,m);
           dfs(i+1,j+1,vis,grid,n,m);
           dfs(i-1,j-1,vis,grid,n,m);
           dfs(i+1,j-1,vis,grid,n,m);
           dfs(i-1,j+1,vis,grid,n,m);
       }
   }
   int numIslands(vector<vector<char>>& grid) {
       // Code here
       int n=grid.size();
       int m=grid[0].size();
       vector<vector<bool>> vis(n,vector<bool>(m,false));
       
       int count=0;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(vis[i][j]==false and grid[i][j]=='1')
               {
                   dfs(i,j,vis,grid,n,m);
                   count++;
               }
           }
       }
       return count;
   }




 



    void bfs(int x, int y, int visited[][501], vector<vector<char>> &grid, int n, int m)
{
    if (x >= n || x < 0 || y >= m || y < 0)
    {
        return;
    }

    if (grid[x][y] == '0')
    {
      return;
    }

if(!visited[x][y])
 { visited[x][y] = 1;
    // aatho direction m jaana h
    bfs(x + 1, y, visited, grid, n, m);
    bfs(x, y + 1, visited, grid, n, m);
    bfs(x - 1, y, visited, grid, n, m);
    bfs(x, y - 1, visited, grid, n, m);
    bfs(x - 1, y - 1, visited, grid, n, m);
    bfs(x + 1, y + 1, visited, grid, n, m);
    bfs(x - 1, y + 1, visited, grid, n, m);
    bfs(x + 1, y - 1, visited, grid, n, m);

 }
    
}
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
    int m = grid[0].size();
    
    int visited[501][501];
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           visited[i][j]=0;
           
       }
   }
   
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) 
        {
            if (!visited[i][j]&&grid[i][j] == '1')
            {
                
                bfs(i, j, visited, grid, n, m);
                count++;
                
            }
        }
    }

    return count;
    }