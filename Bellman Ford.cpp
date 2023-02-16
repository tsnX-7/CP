#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);
#define ll long long
#define pb push_back
#define f first
#define s second
using namespace std;

void BellmanFord(vector<pair<pair<int,int>, int>>&vp, int src, int n, int e)
{
	int dis[n];
	for(int i=0; i<n; i++)
		dis[i] = INT_MAX;
	for(int i=0; i<v-1; i++) {
		for(int j=0; j<e; j++) {
			if(dis[vp[j].f.f]!=INT_MAX and dis[vp[j].f.f]+vp[j].s < dis[vp[j].f.s])
				dis[vp[j].f.s] = dis[vp[j].f.f]+vp[j].s;
		}
	}

	//Neg Cycle Detection
	for(int j=0; j<e; j++) {
		if(dis[vp[j].f.f]!=INT_MAX and dis[vp[j].f.f]+vp[j].s < dis[vp[j].f.s]) {
			cout << "Negative Cycle Detected!" << endl;
		}
	}
}

int main()
{
    fast_io
    
    int n, e; cin >> n >> e;
    vector<pair<pair<int,int>, int>> vp;
    for(int i=0; i>e; i++) {
    	int u,v,w; cin >> u >> v >> w;
    	vp.pb({{u.v},w});
    }
    BellmanFord(vp,0, n, e);
    return 0;
}