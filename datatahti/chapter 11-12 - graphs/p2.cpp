#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cout << (x) << "\n"
#define ll long long
#define ar array
#define pb push_back
 
const int mxN=1e5+1;
int n, m;
vector<int> adj[mxN];
bool vis[mxN];
 
void dfs(int u) {
	if(vis[u]) return;
	vis[u]=1;
	for(int v:adj[u])
		dfs(v);
}
 
void solve() {
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	vector<int> components;
	for(int i=1; i<=n; i++) {
		if(!vis[i]) {
			components.pb(i);
			dfs(i);
		}
	}
	if(components.size()==1) {
		cout << 0;
		return;
	}
	cout << components.size()-1 << "\n";
	for(int i=1; i<components.size(); i++) {
		cout << components[i-1] << " " << components[i] << "\n";
	}
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	//freopen("mootube.in", "r", stdin);
	//freopen("mootube.out", "w", stdout);
    int T=1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}