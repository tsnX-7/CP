#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define sz 200005
using namespace std;

vector<int> adj[sz];
bool vis[sz] = {false};
void dfs(int s, vector<int>&p)
{
   if(!vis[s]) {
      p.push_back(s);
      vis[s] = true;
      for(auto k: adj[s]) {
         if(!vis[k]) dfs(k,p);
      }
   }
}

int main()
{
   int n, m; cin >> n;
   
   for(int i=0; i<m; i++) {
      int u,v; cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
   vector<int> path;
   dfs(1, path);
   //reverse(path.begin(), path.end());
   for(auto i: path) cout << i << " ";
}

/*
4 4
1 3
1 2
2 4
4 3
*/