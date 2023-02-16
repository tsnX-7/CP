#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstring>
#include <queue>
#define inf (1<<20)
using namespace std;

vector<int> toposort(vector<int>adj[], int indeg[], int n)
{
   queue<int> q;
   for(int i=1; i<=n; i++) if(indeg[i]==0) q.push(i);

   vector<int> sorted;
   while(!q.empty()) {
      int x = q.front();
      q.pop();
      sorted.push_back(x);
      for(int i=0; i<adj[x].size(); i++) {
         if(--indeg[ adj[x][i]] == 0) q.push(adj[x][i]);
      }
   }
   return sorted;
}

int main()
{
   int n,m; cin >> n >> m;
   vector<int> adj[n+5];
   int indeg[n+5]; fill_n(indeg, n+5, 0);
   
   for(int i=0; i<m; i++) {
      int u,v; cin >> u >> v;
      adj[u].push_back(v);
      indeg[v]++;
   }
   vector<int> sorted = toposort(adj, indeg, n);
   for(auto i: sorted) cout << i << " ";
   return 0;
}