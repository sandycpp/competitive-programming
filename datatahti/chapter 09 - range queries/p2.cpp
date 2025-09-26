#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cout << (x) << "\n"
#define ll long long
#define ar array
#define pb push_back
 
const int mxN=1001;
int n, m, q, pref[mxN][mxN];
char a[mxN][mxN];
 
 
void solve() {
	cin >> n >> m >> q;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin >> a[i][j];
			if(a[i][j]=='*') pref[i][j]=1;
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+pref[i][j];
			//cout << pref[i][j];
		}
		//cout << "\n";
	}
 
	for(int i=0; i<q; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--, y1--;
		cout << pref[x2][y2]-pref[x1][y2]-pref[x2][y1]+pref[x1][y1] << "\n";
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