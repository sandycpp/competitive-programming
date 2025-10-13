#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cout << (x) << "\n"
#define ll long long
#define ar array
#define pb push_back
 
const int mxN=1e5+1;
int n, m;
 
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
	cin >> n >> m;
	DSU dsu(n);
	int cnt=n;
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		if(!dsu.same(a, b)) {
			cnt--;
			dsu.unite(a, b);
		}
		cout << cnt << " ";
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
