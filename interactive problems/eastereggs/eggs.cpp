#include <bits/stdc++.h>
#include "grader.h"
 
using namespace std;
#define pb push_back
#define f first
#define s second
#define FOR(i, a, b) for(int i=(a); i<(b); ++i)
#define trav(i, x) for(auto& i:x)
 
const int mx = 550;
vector<int> adj[mx], ans;
 
void dfs(int i, int p) {
	ans.pb(i);
	trav(u, adj[i]) {
		if (u != p)
			dfs(u, i);
	}
}

int findEgg (int N, vector < pair < int, int > > bridges)
{
	FOR(i, 0, mx)
		adj[i].clear();
	trav(ii, bridges)
		adj[ii.f].pb(ii.s), adj[ii.s].pb(ii.f);
 
	dfs(1, 0);
 
	//2^9=512
	//bin search on search vector for ans
	int lo = 0, hi = N-1;
	while (lo != hi) {
		int mid = (lo+hi+1)/2;
		vector<int> cur(ans.begin(), ans.begin()+mid);
		if (query(cur))
			hi = mid-1;
		else
			lo = mid;
	}
	return ans[lo];
}