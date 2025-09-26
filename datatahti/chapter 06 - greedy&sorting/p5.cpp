#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cout << (x) << "\n"
#define ll long long
#define ar array
#define pb push_back
#define pf push_front
 
const int mxN=1e5;
int n;
ll a[mxN];
 
void solve() {
	cin >> n;
	for(int i=0; i<n ;i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	if(a[n-1]>accumulate(a, a+n, 0LL)-a[n-1]) {
		cout << 2*a[n-1];
	} else {
		cout << accumulate(a, a+n, 0LL);
	}
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