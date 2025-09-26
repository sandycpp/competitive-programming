#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cout << (x) << "\n"
#define ll long long
#define ar array
#define pb push_back
#define pf push_front
 
const int mxN=50;
int n;
ll dp[mxN+1][2000];
 
void solve() {
	cin >> n;
	int lim=n*(n+1)/2;
	if(lim&1) {
		cout << 0;
		return;
	}
	lim/=2;
	dp[0][0]=1;
	for(int i=1; i<n; i++) {
		for(int j=0; j<=lim; j++) {
			dp[i][j]+=dp[i-1][j];
			if(j-i>=0) dp[i][j]+=dp[i-1][j-i];
		}
	}
	cout << dp[n-1][lim];
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