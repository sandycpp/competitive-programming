#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
 
#define debug(x) cout << (x) << "\n"
#define ll long long
#define ar array
#define pb push_back
#define pf push_front
#define fi first
#define se second
 
const int mxN=1e5+1;
int n, m;
bool act[mxN], vis[mxN];
vector<int> adj[mxN], path, ans;
 
void dfs(int u) {
	vis[u]=1;
	act[u]=1;
	path.pb(u);
	for(int& v:adj[u]) {
		if(act[v]) {
			cout << "10-4\n";
			ans.pb(v);
			int node=v;
			for(int i=path.size()-1; i>=0; --i) {
				ans.pb(path[i]);
				if(path[i]==node) break;
			}
			reverse(ans.begin(), ans.end());
			cout << ans.size() << "\n";
			for(int a:ans)
				cout << a << " ";
			exit(0);
		}
		if(!vis[v])
			dfs(v);
	}
	act[u]=0;
	path.pop_back();
}
 
void solve() {
	cin >> n >> m;
	for(int i=0; i<m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
	}
	for(int i=1; i<=n; ++i) {
		if(!vis[i])
			dfs(i);
	}
 
	cout << "QAQ";
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
