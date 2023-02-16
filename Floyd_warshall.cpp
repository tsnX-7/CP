x#include<iostream>
#include<climits>
#define inf 1<<20
#define sz 10000
using namespace std;

int adj[sz][sz], nxt[sz][sz];

void init(int n)
{
   for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
         if(adj[i][j]==0) {adj[i][j] = inf; nxt[i][j] = -1;}
         else nxt[i][j] = j;
      }
   }
}

void printList(int n)
{
   for(int i=0; i<n; i++) 
      for(int j=0; j<n; j++)
         cout << adj[i][j] << " \n"[j==n-1];
}

void floydWarshall(int n)
{
   for(int k=0; k<n; k++)
      for(int i=0; i<n; i++)
         for(int j=0; j<n; j++)
            if(adj[i][j] > adj[i][k]+adj[k][j]) {
               adj[i][j] = adj[i][k]+adj[k][j];
               //cout << adj[i][j] << endl;
               nxt[i][j] = nxt[i][k];
            }
   return;
}

int main()
{
   int n, m; cin >> n >> m;
   for(int i=0; i<m; i++) {
      int x,y,w; cin >> x >> y >> w;
      adj[x][y] = w;
      adj[y][x] = w;
   }
  
   init(n); printList(n);
   floydWarshall(n);printList(n);
   

   cout << "path printing --- " << endl;
   int p; cin >> p;
   while(p--) {
      int x,y; cin >> x >> y;
      cout << "From " << x << "to " << y << ": " << x << " ";
      while(x!=y) {
         x = nxt[x][y];
         cout << x << " ";
      }cout << endl;

   }
   return 0;
}