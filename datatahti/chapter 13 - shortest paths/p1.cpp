#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define ar array
 
const int mxN=1e5+1;
int n, m;
vector<ar<ll, 2>> adj[mxN];
ll d[mxN];
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].pb({c, b});
	}
	memset(d, 0x3f, sizeof(d));
	d[1]=0;
	priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> pq;
	pq.push({0, 1});
	while(pq.size()) {
		ar<ll, 2> u = pq.top();
		pq.pop();
		if(u[0]>d[u[1]]) continue;
		for(ar<ll, 2> v : adj[u[1]]) {
			if(d[v[1]]>d[u[1]]+v[0]) {
				d[v[1]]=d[u[1]]+v[0];
				pq.push({d[v[1]], v[1]});
			}
		}
	}
	for(int i=1; i<=n; i++) {
		cout << d[i] << " ";
	}
}
