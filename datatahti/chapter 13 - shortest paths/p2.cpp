#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define ar array
 
const int mxN=501;
int n, m, q;
ll d[mxN][mxN];
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> q;
	memset(d, 0x3f, sizeof(d));
	for(int i=0; i<m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		d[a][b]=min(d[a][b], c);
		d[b][a]=min(d[b][a], c);
	}
	for(int i=1; i<=n; i++)
		d[i][i]=0;
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
			}
		}
	}
	for(int i=0; i<q; i++) {
		int a, b;
		cin >> a >> b;
		if(d[a][b]>=1e18) cout << "QAQ\n";
		else cout << d[a][b] << "\n";
	}
}
