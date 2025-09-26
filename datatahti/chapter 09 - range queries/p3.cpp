#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
 
#define debug(x) cout << (x) << "\n"
#define ll long long
#define ar array
#define pb push_back
 
const int mxN=1e5;
int n, q;
ll t[mxN*2];
 
void build() {
	for(int i=n-1; i>0; i--) t[i]=t[i<<1]+t[i<<1|1];
}
 
void upd(int p, int v) {
	for(t[p+=n]=v; p>1; p>>=1) t[p>>1]=t[p]+t[p^1];
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
	for(int i=0; i<n; i++) {
		cin >> t[i+n];
	}
 
	build();
 
	for(int i=0; i<q; i++) {
		char type;
		cin >> type;
		if(type=='!') {
			int p, v;
			cin >> p >> v, p--;
			upd(p, v);
		} else {
			int l, r;
			cin >> l >> r, l--;
			cout << qry(l, r) << "\n";
		}
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