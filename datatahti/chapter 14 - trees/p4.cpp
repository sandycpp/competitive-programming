#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define ar array
 
const int mxN=2e5;
int n;
ll dp[mxN], ans=0;
vector<ar<ll, 2>> adj[mxN];
 
void dfs(int u=0, int p=-1) {
	for(auto& [v, w]:adj[u]) {
		if(v==p) continue;
		dfs(v, u);
		ans=max(ans, dp[u]+dp[v]+w);
		dp[u]=max(dp[u], dp[v]+w);
	}
}
 
void solve() {
	cin >> n;
	for(int i=1; i<n; i++) {
		int a, b, c;
		cin >> a >>  b >> c, --a, --b;
		adj[a].pb({b, c});
		adj[b].pb({a, c});
	}
	dfs();
	cout << ans;
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