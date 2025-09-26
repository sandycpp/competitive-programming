#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cout << (x) << "\n"
#define ll long long
#define ar array
#define pb push_back
 
const int mxN=1e5;
int n, q;
ll t[mxN*2];
 
void build() {
	for(int i=n-1; i>0; i--) t[i] = t[i<<1] + t[i<<1^1];
}
 
ll qry(int l, int r) {
	ll res=0;
	for(l+=n, r+=n; l<r; l>>=1, r>>=1) {
		if(l&1) res+=t[l++];
		if(r&1) res+=t[--r];
	}
	return res;
}
 
void solve() {
	cin >> n >> q;
	for(int i=0; i<n; i++)
		cin >> t[i+n];
 
	build();
	for(int i=0; i<q; i++) {
		int l, r;
		cin >> l >> r, l--;
		cout << qry(l, r) << "\n";
	}
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T=1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}