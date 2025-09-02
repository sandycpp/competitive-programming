#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout << (x) << "\n"
#define pb push_back
#define ar array
 
const int mxN=1e5;
ll n, k;
ll a[mxN];
 
bool e(ll m) {
	ll sum=0;
	for(int i=0; i<n; i++)
		sum+=m/a[i];
	return sum>=k;
}
 
void solve() {
	cin >> n >> k;
	ll mn=INT32_MAX;
	for(int i=0; i<n; i++) {
		cin >> a[i];
		mn=min(mn, a[i]);
	}
		
	ll l=1, r=k*mn;
	while(l<r) {
		ll m=l+(r-l)/2;
		if(e(m)) {
			r=m;
		} else {
			l=m+1;
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
