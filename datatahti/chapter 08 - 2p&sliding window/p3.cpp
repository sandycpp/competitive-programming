#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cout << (x) << "\n"
#define ll long long
#define ar array
#define pb push_back
#define pf push_front
#define fi first
#define se second
 
const int mxN=1e5;
const ll inf=1e15;
int n, a, b;
ll pref[mxN+1];
 
void solve() {
	cin >> n >> a >> b;
	for(int i=1; i<=n; i++) {
		cin >> pref[i];
		pref[i]+=pref[i-1];
	}
	multiset<ll> window;
	ll ans=-inf;
	for(int i=0; i<=n; i++) {
		if(i-b>0) window.erase(window.find(pref[i-b-1]));
		if(i-a>=0) {
			window.insert(pref[i-a]);
			ans=max(ans, pref[i]-*(window.begin()));
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