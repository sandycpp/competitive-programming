#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cout << (x) << "\n"
#define ll long long
#define ar array
#define pb push_back
#define pf push_front
 
const int M=1e9+7, mxN=1001;
int n, m, dp[mxN][mxN];
char a[mxN][mxN];
 
void solve() {
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin >> a[i][j];
		}
	}
	if(a[1][1]!='*') dp[1][1]=1;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(i==1 && j==1) continue;
			dp[i][j]=(dp[i-1][j]+dp[i][j-1])%M;
			if(a[i][j]=='*') dp[i][j]=0;
		}
	}
	cout << dp[n][m];
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