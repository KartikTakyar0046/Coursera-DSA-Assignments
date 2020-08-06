#include <iostream>
#include <vector>
#include <queue>
#include<list>
using std::list;
using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj,int n,int src) {
  list<int> queue;
  //write your code here
  int color[n];
  for(int i=0;i<n;i++)
  {
    color[i]=-1;
  }
  queue.push_back(src);
  while(!queue.empty())
  {
    int u=queue.front();
    color[u]=1;
    queue.pop_front();
    if (adj[u][u] == 1) 
        return false;  
  
        // Find all non-colored adjacent vertices 
        for (int v = 0; v < n; ++v) 
        { 
            // An edge from u to v exists and  
            // destination v is not colored 
            if (adj[u][v] && color[v] == -1) 
            { 
                // Assign alternate color to this adjacent v of u 
                color[v] = 1 - color[u]; 
                queue.push_back(v); 
            } 
  
            // An edge from u to v exists and destination  
            // v is colored with same color as u 
            else if (adj[u][v] && color[v] == color[u]) 
                return 0;
        } 
  }
  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  int src;
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    src=x;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj,n,src);
}
