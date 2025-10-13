#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cout << (x) << "\n"
#define ll long long
#define ar array
#define pb push_back
 
const int mxN=1e5+1;
int n, m, k;
 
struct DSU{
	vector<int> link, size;
	DSU(int n) {
		link.resize(n+1);
		size.assign(n+1, 1);
		for(int i=1; i<=n; i++) {
			link[i]=i;
		}
	}
 
	int find(int x) {
		return link[x] == x? x : link[x] = find(link[x]);
	}
	
	bool same(int a, int b) {
		return find(a) == find(b);
	}
 
	void unite(int a, int b) {
		a = find(a);
		b = find(b);
		if(a==b) return;
		if(size[a]<size[b]) {
			link[a]=b;
			size[b]+=size[a];
		} else {
			link[b]=a;
			size[a]+=size[b];
		}
	}
};
 
 
void solve() {
	cin >> n >> m;
	DSU dsu(n);
	int ans=INT32_MAX, cnt=0;
	vector<ar<int, 3>> edges;
	edges.reserve(m);
	for(int i=0; i<m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({w, u, v});
	}
	sort(edges.rbegin(), edges.rend());
	for(auto &[w, u, v] : edges) {
		if(!dsu.same(u, v)) {
			dsu.unite(u, v);
			if(w < ans) ans = w;
		}
		if(cnt==n-1) break;
	}
	cout << ans << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	//freopen("mootube.in", "r", stdin);
	//freopen("mootube.out", "w", stdout);
    //cin >> T;
	solve();
    return 0;
}
