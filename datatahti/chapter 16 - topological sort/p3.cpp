#include <bits/stdc++.h>
using namespace std;
 
//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
 
#define debug(x) cout << (x) << "\n"
#define ll long long
#define ar array
#define pb push_back
#define pf push_front
#define fi first
#define se second
 
const int mxN=1e5+1;
int n, m, dp[mxN], p[mxN];
bool vis[mxN];
vector<int> adj[mxN], topo, ans;
 
void dfs(int u=1) {
	vis[u]=1;
	for(int v:adj[u]) {
		if(!vis[v])
			dfs(v);
	}
	topo.pb(u);
}
 
void solve() {
	cin >> n >> m;
	for(int i=0; i<m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
	}
	dfs();
	reverse(topo.begin(), topo.end());
	for(int& u:topo) {
		for(int v:adj[u]) {
			if(dp[v]<dp[u]+1) p[v]=u;
			dp[v]=max(dp[v], dp[u]+1);
		}
	}
	if(!vis[n]) {
		cout << "QAQ";
	} else {
		int u=n;
		while(u^1) {
			ans.pb(u);
			u=p[u];
		}
		ans.pb(1);
		cout << "10-4\n" << dp[n]+1 << "\n";
		for(int i=ans.size()-1; i>=0; --i) 
			cout << ans[i] << " ";
	}
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int T=1;
    //cin >> T;
	while(T--)
		solve();
    return 0;
}
