
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstring>
#include <queue>
#define inf (1<<20)
using namespace std;

int dijkstra(vector<int>adj[], vector<int>w[], int par[], int n)
{
   int cost[n+5]; fill_n(cost, n+5, inf);
   
   priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>> > min_pq;
   min_pq.push({1,0});
   cost[1] = 0;
   while(!min_pq.empty()) {
      int node = min_pq.top().first;
      int cst = min_pq.top().second;
      min_pq.pop();
      for(int i=0; i<adj[node].size(); i++) {
         if(cost[ adj[node][i] ] > cst + w[node][i]) {
            cost[ adj[node][i] ] = cst + w[node][i];
            min_pq.push({adj[node][i], cost[ adj[node][i]]});
            par[ adj[node][i] ] = node;   
         }
      }
   }
   return cost[1];
}

int main()
{
   int n,m; cin >> n >> m; 
   vector<int> adj[n+5],w[n+5];
   
   for(int i=0; i<m; i++) {
      int u,v, wg; cin >> u >> v >> wg;
      adj[u].push_back(v);
      //adj[v].push_back(u);
      w[u].push_back(wg);
      //w[v].push_back(wg);
   }
   int par[n+5]; memset(par, -1, sizeof par);
   cout << dijkstra(adj, w, par, n);
}