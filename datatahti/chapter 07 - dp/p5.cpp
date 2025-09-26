#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cout << (x) << "\n"
#define ll long long
#define ar array
#define pb push_back
#define pf push_front
 
const int mxN=1000, mxX=1e5+1;
int n, x, p[mxN], v[mxN];
ll dp[mxX];
 
void solve() {
	cin >> n >> x;
	fill(dp, dp+x, INT32_MIN);
	dp[0]=0;
	for(int i=0; i<n; i++)
		cin >> p[i];
	for(int i=0; i<n; i++)
		cin >> v[i];
	ll ans=0;
	for(int i=0; i<n; i++) {
		for(int j=x; j>=p[i]; j--) {
			dp[j]=max(dp[j], dp[j-p[i]]+v[i]);
			ans=max(ans, dp[j]);
		}
	}
	cout << ans << "\n";
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