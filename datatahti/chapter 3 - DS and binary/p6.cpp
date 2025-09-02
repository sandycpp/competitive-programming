#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define debug(x) cout << (x) << "\n"
#define pb push_back
#define ar array
 
const int mxN=1e5;
ll n, k, a[mxN];
 
bool e(ll m) {
	ll sum=0, cnt=1;
	for(int i=0; i<n; i++) {
		if(a[i]>m) return 0;
		if(sum+a[i]>m) {
			cnt++;
			sum=a[i];
		} else {
			sum+=a[i];
		}
	}
	return cnt<=k;
}
 
void solve() {
	cin >> n >> k;
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	ll l=1, r=accumulate(a, a+n, 0LL);
	while(l<r) {
		ll m=l+(r-l)/2;
		if(!e(m)) {
			l=m+1;
		} else {
			r=m;
		}
	}
	cout << l;
}
 
int main() {
	int T=1;
	//cin >> T;
	while(T--)
		solve();
	return 0;
}
