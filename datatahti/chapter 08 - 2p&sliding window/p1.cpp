#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cout << (x) << "\n"
#define ll long long
#define ar array
#define pb push_back
#define pf push_front
 
const int mxN=1e5;
int n, a[mxN];
 
void solve() {
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	multiset<int> seen;
	int ans=0, cur=0;
	seen.insert(a[0]);
	for(int i=0, j=0; i<n; i++) {
		while(j<n) {
			if(!seen.count(a[j+1])) {
				j++;
				seen.insert(a[j]);
			} else {
				break;
			}
		}
		cur=j-i+1;
		if(j==n) cur--;
		ans=max(ans, cur);
		//cout << i << "\n";
		//for(int u:seen) {
			//cout << u << " ";
		//}
		//cout << "\n";
		if(seen.count(a[i]))
			seen.erase(seen.find(a[i]));
	}
	cout << ans << "\n";
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