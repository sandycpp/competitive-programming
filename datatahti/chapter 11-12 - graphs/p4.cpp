#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cout << (x) << "\n"
#define ll long long
#define ar array
#define pb push_back
 
const int mxN=1e5+1;
int n, m, d[mxN], p[mxN];
vector<int> adj[mxN];
bool vis[mxN];
 
 
void solve() {
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
 
	queue<int> q;
	q.push(1);
	vis[1]=1;
	d[1]=1;
	while(q.size()) {
		int u=q.front();
		q.pop();
		for(int v:adj[u]) {
			if(vis[v]) continue;
			vis[v]=1;
			q.push(v);
			d[v]=d[u]+1;
			p[v]=u;
		}
	}
	if(!vis[n]) {
		cout << "QAQ";
	} else {
		cout << "10-4\n";
		cout << d[n] << "\n";
		vector<int> ans;
		int x=p[n];
		ans.pb(n);
		while(x!=1) {
			ans.pb(x);
			x=p[x];
		}
		ans.pb(1);
		reverse(ans.begin(), ans.end());
		for(int num:ans) {
			cout << num << " ";
		}
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