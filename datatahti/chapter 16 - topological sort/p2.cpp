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
int n, m, s[mxN];
vector<int> adj[mxN], ans;
 
void dfs(int u) {
	s[u]=1;
	for(int v:adj[u]) {
		if(s[v]==1) {
			cout << "QAQ";
			exit(0);
		}
		if(s[v]==0) {
			dfs(v);
		}
	}
	s[u]=2;
	ans.pb(u);
}
 
void solve() {
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
	}
	for(int i=1; i<=n; i++)
		if(s[i]==0)
			dfs(i);
	cout << "10-4" << "\n";
	for(int i=ans.size()-1; i>=0; i--)
		cout << ans[i] << " ";
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
