#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> adj[1000];
int par[1000];
bool vis[1000];
///decalre them global

int bfs(int s, int d)
{
   queue<pair<int,int>> q;
   q.push({s,0});
   vis[s] = true;
   
   while(!q.empty()) {
      int node = q.front().first;
      int cost = q.front().second;
      q.pop();
      if(node == d) return cost;
      for(int i=0; i<adj[node].size(); i++) {
         int u = adj[node][i];
         if(!vis[u]) {
            q.push({u, cost+1});
            vis[u] = true;
            par[u] = node;
         }
      }
   }
   return -1;
}



void printMatrix(int n)
{
    for (int i = 0; i<n; i++)
        for (int j = 0; j<adj[i].size(); j++)
            cout << adj[i][j] << " \n"[j==adj[i].size()-1];
}
void init(int n) ///init using function or loop
{
    for (int i = 0; i < n; i++)
        par[i] = -1;
}

int main()
{
   int n, m; cin >> n >> m;
   
   init(n);
   for(int i=0; i<m; i++) {
      int x, y; cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
   }
   printMatrix(n);
   cin >> m;
   while(m--) {
      int x,y; cin >> x >> y;
      int w = bfs(x, y);
      cout << "Min cost from " << x << "to " << y << ": " << w << " ---> "; 
      if(~w) {
         vector<int> path;
         while(~y) {
            path.push_back(y);
            y = par[y];
         }
         reverse(path.begin(), path.end());
         for(int i=0; i<path.size(); i++) cout << path[i] << " \n"[i==path.size()-1];
      }
   }
   return 0;
}