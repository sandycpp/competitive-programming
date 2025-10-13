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
int n, m, who[mxN];
bool vis[mxN];
vector<int> adj[mxN], adj2[mxN], st;
 
void dfs(int u) {
	vis[u]=1;
	for(int v:adj[u]) {
		if(!vis[v])
			dfs(v);
	}
	st.pb(u);
}
 
void dfs2(int u, int r) {
	vis[u]=0;
	who[u]=r;
	for(int v:adj2[u]) {
		if(vis[v])
			dfs2(v, r);
	}
}
 
void solve() {
	cin >> n >> m;
	for(int i=0, a, b; i<m; ++i) {
		cin >> a >> b;
		adj[a].pb(b);
		adj2[b].pb(a);
	}
 
	for(int i=1; i<=n; ++i) {
		if(!vis[i])
			dfs(i);
	}
	int c=0;
	for(int i=n-1; ~i; --i) {
		if(vis[st[i]]) {
			c++;
			dfs2(st[i], c);
		}
	}
	cout << c << "\n";
	for(int i=1; i<=n; i++) {
		cout << who[i] << " ";
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
