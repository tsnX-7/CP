#include <bits/stdc++.h>
#define ll long long
using namespace std;


void buildTree(int *a, int s, int e, int *tree, int idx)
{
	if(s==e) {
		tree[idx] = a[s];
		return;
	}
	int mid = (s+e)/2;
	buildTree(a, s, mid, tree, 2*idx);
	buildTree(a, mid+1, e, tree, 2*idx+1);
	tree[idx] = min(tree[2*idx], tree[2*idx+1]);
	return;
}

int query(int *tree, int ss, int se, int qs, int qe, int idx)
{
	if(qs<=ss and qe>=se){
		return tree[idx];
	}
	if(qe<ss or qs>se){
		return INT_MAX;
	}
	int mid = (ss+se)/2;
	int left = query(tree, ss, mid, qs, qe, 2*idx);
	int right = query(tree, mid+1, se, qs, qe, 2*idx+1);
	return min(left, right);
}

void updNode(int *tree, int ss, int se, int i, int inc, int idx)
{
	if(i<ss or i>se) return;
	if(ss==se) {
		tree[idx] += inc;
		return;
	}

	int mid = (ss+se)/2;
	updNode(tree, ss, mid, i, inc, 2*idx);
	updNode(tree, mid+1, se, i, inc, 2*idx+1);
	tree[idx] = min(tree[2*idx], tree[2*idx+1]);
	return;
}

int main()
{
   int n = 6;
   int a[] = {1,3,2,-5,6,4};

   int *tree = new int[4*n+1];
   buildTree(a, 0, n-1, tree, 1);

   updNode(tree, 0, n-1, 3, 10, 1);
   int q; cin >> q;
   while(q--) {
   	int l, r; cin >> l >> r;
   	cout << query(tree, 0, n-1, l, r, 1) << endl;
   }

   for(int i=0; i<13; i++) {
   	cout << tree[i] << " "; 
   }cout << endl;
   
   return 0;
}   