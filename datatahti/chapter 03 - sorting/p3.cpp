#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define debug(x) cout << (x) << "\n"
#define pb push_back
#define ar array
 
const int mxN=1e5;
int n, k, a[mxN];
 
void solve() {
	cin >> n >> k;
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	int i=0, j=n-1, ans=0;
	while(i<j) {
		if(a[i]+a[j]>k) {
			j--, ans++;
		} else {
			j--, i++, ans++;
		}
	}
	if(i==j) ans++;
	cout << ans << "\n";
}
 
int main() {
	int T=1;
	//cin >> T;
	while(T--)
		solve();
	return 0;
}
