#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define ar array
 
const int mxN=1e5+1;
int n, dp[mxN];
vector<int> adj[mxN];
 
void dfs(int u=1, int p=0) {
	for(int v:adj[u]) {
		if(v==p) continue;
		dfs(v, u);
		dp[u]+=dp[v]+1;
	}
}
 
int main() {
	cin >> n;
	for(int i=2; i<=n; i++) {
		int a;
		cin >> a;
		adj[a].pb(i);
	}
	dfs();
	for(int i=1; i<=n; i++) {
		cout << dp[i] << " ";
	}
}