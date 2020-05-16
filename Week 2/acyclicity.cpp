#include <iostream>
#include <vector>

using std::vector;
using std::pair;
vector<bool> visited, recstack;
int iscyclic(int i,vector<vector<int> >&adj)
{
	if(!visited[i])
	{
		visited[i]=true;
		recstack[i]=true;
		for(int m=0;m<adj[i].size();m++)
		{
			int w=adj[i][m];
			if(!visited[w] && iscyclic(w, adj))
			return 1;
			else if(recstack[w])
			return 1;
		}
	}
	recstack[i]=false;
	return 0;	
}
int acyclic(vector<vector<int> > &adj) {
	 visited.resize(adj.size());
    recstack.resize(adj.size());

	for(int i=0;i<adj.size();i++)
	{
		if(iscyclic(i,adj))
		return 1;
}
  //write your code here
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
