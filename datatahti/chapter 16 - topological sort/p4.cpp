#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define ar array
 
const int mxN=1e5+1, M=1e9+7;
int n, m, dp[mxN];
bool vis[mxN];
vector<int> adj[mxN], radj[mxN], topo;
 
void dfs(int u) {
	vis[u]=1;
	for(int v:adj[u]) {
		if(!vis[v])
			dfs(v);
	}
	topo.pb(u);
}
 
void solve() {
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		radj[b].pb(a);
	}
	
	for(int i=1; i<=n; i++) {
		if(!vis[i])
			dfs(i);
	}
	
	reverse(topo.begin(), topo.end());
	dp[1]=1;
	for(int i=1; i<n; i++) {
		int u=topo[i];
		for(int v:radj[u]) {
			dp[u]=(dp[u]+dp[v])%M;
		}
	}
	cout << dp[n];
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T=1;
	//cin >> T;
	while(T--) {
		solve();
	}
}