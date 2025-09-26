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
 
const int mxN=1e5;
int n;
ar<int, 2> a[mxN];
 
void solve() {
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a[i][0] >> a[i][1];
	}
	sort(a, a+n);
	ll ans=0, cur=0;
	for(int i=0; i<n; i++) {
		cur+=a[i][0];
		ans+=a[i][1]-cur;
	}
	cout << ans << "\n";
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