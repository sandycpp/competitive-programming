#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cout << (x) << "\n"
#define ll long long
#define ar array
#define pb push_back
 
const int mxN=1e5;
int n, q;
ll t[mxN*2];
 
void upd(int l, int r, int v) {
	for(l+=n, r+=n; l<r; l>>=1, r>>=1) {
		if(l&1) t[l++]+=v;
		if(r&1) t[--r]+=v;
	}
}
 
ll qry(int p) {
	ll res=0;
	for(p+=n; p>0; p>>=1) res+=t[p];
	return res;
}
 
void solve() {
	cin >> n >> q;
	for(int i=0; i<n; i++) {
		cin >> t[i+n];
	}
 
	for(int i=0; i<q; i++) {
		char type;
		cin >> type;
		if(type=='!') {
			int l, r;
			cin >> l >> r, l--;
			upd(l, r, 1);
		} else {
			int p;
			cin >> p, p--;
			cout << qry(p) << "\n";
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