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
		for(int i=1; i<=n; i++) link[i]=i;
	}
 
	int find(int x) {
		while(x!=link[x]) x=link[x];
		return x;
	}
 
	bool same(int a, int b) {
		return find(a) == find(b);
	}
 
	void unite(int a, int b) {
		a = find(a);
		b = find(b);
		if(a==b) return;
		if(size[a]<size[b]) swap(a, b);
		size[a]+=size[b];
		link[b]=a;
	}
};
 
 
void solve() {
	cin >> n >> m >> k;
	DSU dsu(n);
	int cnt=n;
	vector<ar<int, 2>> edges(m);
	vector<ar<int, 2>> queries(k);
	set<ar<int, 2>> seen;
	for(int i=0; i<m; i++) {
		cin >> edges[i][0] >> edges[i][1];
	}
	for(int i=0; i<k; i++) {
		cin >> queries[i][0] >> queries[i][1];
		seen.insert({queries[i][0], queries[i][1]});
		seen.insert({queries[i][1], queries[i][0]});
	}
	for(int i=0; i<m; i++) {
		if(seen.find({edges[i][0], edges[i][1]}) != seen.end()) continue;
 
		int a = edges[i][0];
		int b = edges[i][1];
 
		if(!dsu.same(a, b)) {
			cnt--;
			dsu.unite(a, b);
		}
	}
	reverse(queries.begin(), queries.end());
	vector<int> ans;
	for(int i=0; i<k ;i++) {
		ans.pb(cnt);
		int a=queries[i][0];
		int b=queries[i][1];
		if(!dsu.same(a, b)) {
			dsu.unite(a, b);
			cnt--;
		}
	}
	for(int i=k-1; i>=0; i--) {
		cout << ans[i] << " ";
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