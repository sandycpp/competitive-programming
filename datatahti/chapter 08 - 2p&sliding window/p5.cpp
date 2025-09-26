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
const int inf = 1e9+1;
int n;
ll k[mxN+1];
 
void solve() {
	cin >> n;
	for(int i=1; i<=n; i++)
		cin >> k[i];
	vector<ll> left(n+1), right(n+1, n+1);
	stack<pair<ll, int>> s;
	s.push({0, 0});
	for(int i=1; i<=n; i++) {
		while(s.size() && k[i]<=s.top().fi) s.pop();
		left[i]=s.top().se;
		s.push({k[i], i});
	}
	while(s.size()) s.pop();
	for(int i=1; i<=n; i++) {
		while(s.size() && k[i]<s.top().fi) {
			right[s.top().se]=i;
			s.pop();
		}
		s.push({k[i], i});
	}
	ll ans=-inf;
	for(int i=1; i<=n; i++) {
		ans=max(ans, k[i]*(right[i]-left[i]-1));
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