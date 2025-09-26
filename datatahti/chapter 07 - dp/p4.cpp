#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cout << (x) << "\n"
#define ll long long
#define ar array
#define pb push_back
#define pf push_front
 
string a, b;
 
void solve() {
	cin >> a >> b;
	int n = a.size();
	int m = b.size();
 
	vector<vector<int>> dp(n+1, vector<int>(m+1));
	for(int i=0; i<=m; i++) {
		dp[0][i]=i;
	}
	for(int i=0; i<=n; i++) {
		dp[i][0]=i;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			int cost = (a[i-1]==b[j-1]?0:1);
			dp[i][j]=min(dp[i][j-1]+1, min(dp[i-1][j]+1, dp[i-1][j-1]+cost));
		}
	}
	//for(int i=0; i<=n; i++) {
		//for(int j=0; j<=m; j++) {
			//cout << dp[i][j] << " ";
		//}
		//cout << "\n";
	//}
	cout << dp[n][m] << "\n";
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