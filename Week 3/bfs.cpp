#include <iostream>
#include <vector>
#include <queue>
#include<bits/stdc++.h>
#include<climits>
using std::vector;
using std::queue;
using std::list;
int distance(vector<vector<int> > &adj, int s, int t,int n) {
  //write your code here
  list<int> queue;
  queue.push_back(s);
  bool visited[n];
  for(int i=0;i<n;i++)
  visited[i]=false;
  visited[s]=true;
  int distance[n];
  for(int i=0;i<n;i++)
  distance[i]=INT_MAX;
  distance[s]=0;
  while(!queue.empty())
  {
    int u=queue.front();
    queue.pop_front();
    for(int i=0;i<adj[u].size();i++)
    {
      if(!visited[adj[u][i]])
      {
        distance[adj[u][i]]=distance[u]+1;
        visited[adj[u][i]]=true;
        queue.push_back(adj[u][i]);
        if(adj[u][i]==t)
        return distance[adj[u][i]];
      }
    }
  }
  return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t,n);
}
