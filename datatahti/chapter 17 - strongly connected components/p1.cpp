#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define ar array
 
const int mxN=1e5+1;
int n, m;
bool vis[mxN][2];
vector<int> adj[mxN][2];
 
void dfs(int u, int dir) {
	vis[u][dir]=1;
	for(int v:adj[u][dir]) {
		if(!vis[v][dir])
			dfs(v, dir);
	}
		
}
 
void solve() {
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a][0].pb(b);
		adj[b][1].pb(a);
	}
	dfs(1, 0);
	for(int i=1; i<=n; ++i) {
		if(!vis[i][0]) {
			cout << "QAQ\n";
			cout << "1 " << i;
			return;
		}
	}
	dfs(1, 1);
	for(int i=1; i<=n; ++i) {
		if(!vis[i][1]) {
			cout << "QAQ\n";
			cout << i << " 1";
			return;
		}
	}
	cout << "10-4";
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