#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define debug(x) cout << (x) << "\n"
#define pb push_back
#define ar array
 
int n;
 
void solve() {
	cin >> n;
	vector<ar<int, 2>> a;
	for(int i=0; i<n; i++) {
		int l, r;
		cin >> l >> r;
		a.pb({l, 1});
		a.pb({r, -1});
	}
	sort(a.begin(), a.end());
	int c=0, mx=0;
	for(int i=0; i<2*n; i++) {
		c+=a[i][1];
		mx=max(mx, c);
	}
	cout << mx;
}
 
int main() {
	int T=1;
	//cin >> T;
	while(T--)
		solve();
	return 0;
}

