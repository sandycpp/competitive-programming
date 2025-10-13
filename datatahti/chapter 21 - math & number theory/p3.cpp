#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cout << (x) << "\n"
#define ll long long
#define ar array
#define pb push_back
#define pf push_front
#define fi first
#define se second
 
const int mxN=1e6;
int n, sieve[mxN+1];
 
void solve() {
	cin >> n;
	int ans=1;
	while(n>1) {
		int div=sieve[n];
		int cnt=0;
		while(n%div==0) {
			cnt++;
			n/=div;
		}
		ans*=cnt+1;
	}
	cout << ans << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	for(int x=2; x<=mxN; x++) {
		if(sieve[x]) continue;
		for(int u=x; u<=mxN; u+=x)
			sieve[u]=x;
	}
	int T=1;
    cin >> T;
	while(T--)
		solve();
    return 0;
}