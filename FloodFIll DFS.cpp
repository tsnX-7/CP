#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;


const int N 1000; //max size
int g[N][N]; //the grid
bool vis[N][N]; //visited array
int row, col;


void floodfill(int r, int c, int color)
{
	if(r<0 or r>=row or c<0 or c>=col or g[r][c]!=color or vis[r][c]) return;

	vis[r][c] = true;

	floodfill(r-1, c, color);
	floodfill(r, c+1, color);
	floodfill(r+1, c, color);
	floodfill(r, c-1, color);
}

int main()
{
	fast_io
	cin >> row >> col;
	for(int i=0; i<row; i++) {
		for(int j=0; j<col; j++) {
			cin >> g[i][j];
		}
	}
	int sr, sc; cin >> sr >> sc;
	floodfill(sr, sc, g[sr][sc]);

	return 0;
}