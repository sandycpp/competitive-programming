#include<bits/stdc++.h>
using namespace std;
 
void setIO(string name="") {
	if(name.length()) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}
 
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define debug(x) cout << (x) << "\n"
#define ar array
#define fi first
#define se second
 
const int mxN=2e5, lim=1e9+1;
int n, a[mxN], ans[mxN];
 
void solve() {
	cin >> n;
	stack<pair<int, int>> s;
	
	for(int i=0; i<n; i++)
		cin >> a[i];
	s.push({lim, -1});
	for(int i=0; i<n; i++) {
		while(s.size() && a[i]>s.top().fi) {
			ans[s.top().se] = a[i];
			s.pop();
		}
		s.push({a[i], i});
	}
	for(int i=0; i<n; i++) 
		cout << ans[i] << " ";
}
 
int main() {
	cin.tie(0) -> sync_with_stdio(0);
	//setIO("sleepy");
	int T=1;
	//cin >> T;
	while(T--)
		solve();
	return 0;
}