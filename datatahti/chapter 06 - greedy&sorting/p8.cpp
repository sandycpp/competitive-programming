#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cout << (x) << "\n"
#define ll long long
#define ar array
#define pb push_back
 
int k, n;
 
 
void solve() {
	cin >> n >> k;
	vector<ar<int, 2>> movies(n);
	multiset<int> members;
 
	for(int i=0; i<n; i++) {
		cin >> movies[i][1] >> movies[i][0];
	}
	for(int i=0; i<k; i++) members.insert(0);
 
	sort(movies.begin(), movies.end());
	int ans=0;
	for(int i=0; i<n; i++) {
		auto mn=members.begin();
		if(movies[i][1]<*mn) continue;
		auto it=members.upper_bound(movies[i][1]);
		it--;
		members.erase(it);
		members.insert(movies[i][0]);
		ans++;
	}
	cout << ans << "\n";
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
