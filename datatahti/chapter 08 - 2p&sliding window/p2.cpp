#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cout << (x) << "\n"
#define ll long long
#define ar array
#define pb push_back
#define pf push_front
 
const int mxN=5000;
int n;
ll x, a[mxN];
 
void solve() {
	cin >> n >> x;
	for(int i=0; i<n ;i++)
		cin >> a[i];
	sort(a, a+n);
	//for(int i=0; i<n; i++) {
		//cout << a[i] << " ";
	//}
	for(int i=0; i<n-2; i++) {
		int l=i+1, r=n-1;
		while(l<r) {
			ll sum=a[i]+a[l]+a[r];
			if(sum==x) {
				cout << a[i] << " " << a[l] << " "<< a[r];
				return;
			}
			if(sum<x) {
				l++;
			} else {
				r--;
			}
		}
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