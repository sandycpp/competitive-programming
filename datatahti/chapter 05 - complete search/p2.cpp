#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout << (x) << "\n"
#define pb push_back
#define ar array
 
int n;
 
int main() {
	cin >> n;
	vector<ll> a(n);
	ll total=0;
	for(int i=0; i<n; i++) {
		cin >> a[i];
		total+=a[i];
	}
	ll ans=accumulate(a.begin(), a.end(), 0LL);
	for(int b=0; b<(1<<n); b++) {
		ll sum=0;
		for(int i=0; i<n; i++) {
			if(b&(1<<i)) sum+=a[i];
		}
		ans=min(ans, abs(sum-(total-sum)));
	}
	cout << ans;
    return 0;
}
