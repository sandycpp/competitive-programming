#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
void setIO(string name="") {
    if(name.length()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}
 
#define ll long long
#define pb push_back
#define ar array
 
const int mxN=2e5+1, inf=1e9;
int n, q, a[mxN];
Tree<pair<int, int>> s;
 
void solve() {
	cin >> n >> q;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		s.insert({a[i], i});
	}
	for(int i=0; i<q; i++) {
		char t;
		cin >> t;
		if(t=='!') {
			int k, x;
			cin >> k >> x;
			s.erase({a[k], k});
			a[k]=x;
			s.insert({a[k], k});
		} else {
			int a, b;
			cin >> a >> b;
			cout << s.order_of_key({b, inf}) - s.order_of_key({a-1, inf}) << "\n";
		}
	}
}
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //setIO("moocast");
    int t=1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}