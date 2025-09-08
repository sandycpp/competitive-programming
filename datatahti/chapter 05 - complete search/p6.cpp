#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cout << (x) << "\n"
#define ll long long
#define ar array
#define pb push_back
#define pf push_front
 
const int mxN=40;
ll n, x;
ll a[mxN];
 
int main() {
	cin >> n >> x;
	int n1 = n/2;
	int n2 = n-n1;
	vector<int> left(n1);
	vector<int> right(n2);
	for(int i=0; i<n1; i++) {
		cin >> left[i];
	}
	for(int i=0; i<n2; i++) {
		cin >> right[i];
	}
	unordered_map<ll, ll> m;
 
	for(int b=0; b<(1<<n1); b++) {
		ll sum=0;
		for(int i=0; i<n1; i++) {
			if(b&(1<<i)) sum+=left[i];
		}
		m[sum]++;
	}
	ll ans=0;
	for(int b=0; b<(1<<n2); b++) {
		ll sum=0;
		for(int i=0; i<n2; i++) {
			if(b&(1<<i)) sum+=right[i];
		}
		ans+=m[x-sum];
	}
	cout << ans << "\n";
    return 0;
}
