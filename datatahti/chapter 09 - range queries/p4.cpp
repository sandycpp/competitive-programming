#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cout << (x) << "\n"
#define ll long long
#define ar array
#define pb push_back
 
const int mxN=1e5;
int n, q;
ll tmax[mxN*2], tmin[mxN*2];
 
void buildmax() {
	for(int i=n-1; i>0; i--) tmax[i]=max(tmax[i<<1],tmax[i<<1|1]);
}
 
void buildmin() {
	for(int i=n-1; i>0; i--) tmin[i]=min(tmin[i<<1],tmin[i<<1|1]);
}
 
void updmax(int p, int v) {
	for(tmax[p+=n]=v; p>1; p>>=1) tmax[p>>1]=max(tmax[p],tmax[p^1]);
}
 
void updmin(int p, int v) {
	for(tmin[p+=n]=v; p>1; p>>=1) tmin[p>>1]=min(tmin[p],tmin[p^1]);
}
 
ll qrymax(int l, int r) {
	ll res=0;
	for(l+=n, r+=n; l<r; l>>=1, r>>=1) {
		if(l&1) res=max(res,tmax[l++]);
		if(r&1) res=max(res,tmax[--r]);
	}
	return res;
}
 
ll qrymin(int l, int r) {
	ll res=INT32_MAX;
	for(l+=n, r+=n; l<r; l>>=1, r>>=1) {
		if(l&1) res=min(res,tmin[l++]);
		if(r&1) res=min(res,tmin[--r]);
	}
	return res;
}
 
void solve() {
	cin >> n >> q;
	for(int i=0; i<n; i++) {
		cin >> tmax[i+n];
		tmin[i+n]=tmax[i+n];
	}
 
	buildmax();
	buildmin();
 
	for(int i=0; i<q; i++) {
		char type;
		cin >> type;
		if(type=='!') {
			int p, v;
			cin >> p >> v, p--;
			updmax(p, v);
			updmin(p, v);
		} else {
			int l, r;
			cin >> l >> r, l--;
			cout << qrymin(l, r) << " " << qrymax(l, r) << "\n";
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