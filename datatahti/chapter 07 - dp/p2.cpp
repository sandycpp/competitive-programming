#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cout << (x) << "\n"
#define ll long long
#define ar array
#define pb push_back
#define pf push_front
 
const int mxN=1e6;
int n;
ll dp[mxN+1];
 
void solve() {
	cin >> n;
	fill(dp, dp+n, INT32_MAX);
	dp[n]=0;
	for(int i=n; i>0; i--) {
		int j=i;
		while(j>0) {
			int dig = j%10;
			if(i-dig>=0) dp[i-dig]=min(dp[i-dig], dp[i]+1);
			j/=10;
		}
	}
	cout << dp[0] << "\n";
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