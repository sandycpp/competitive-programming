#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define ar array
 
const int mxN=1e5+1;
int n, ans=0;
bool used[mxN];
vector<int> adj[mxN];
 
void dfs(int u=1, int p=0) {
	for(int v:adj[u]) {
		if(v==p) continue;
		dfs(v, u);
		if(!used[v] && !used[u]) {
			ans++;
			used[v]=1;
			used[u]=1;
		}
	}
}
 
void solve() {
	cin >> n;
	for(int i=1; i<n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
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