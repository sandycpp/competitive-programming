#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define ar array
 
const int mxN=1e5+1;
int n;
ll x, dp[mxN];
vector<int> adj[mxN];
 
void dfs(int u=1, int p=0) {
	for(int v:adj[u]) {
		if(v==p) continue;
		dp[v]=dp[u]/adj[u].size();
		dfs(v, u);
	}
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> x >> n;
	for(int i=2; i<=n; i++) {
		int a;
		cin >> a;
		adj[a].pb(i);
	}
	dp[1]=x;
	dfs();
	for(int i=1; i<=n; i++) {
		cout << dp[i] << " ";
	}
}