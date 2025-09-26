#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cout << (x) << "\n"
#define ll long long
#define ar array
#define pb push_back
#define pf push_front
 
string s;
 
void solve() {
	cin >> s;
	int n=s.size();
	set<char> seen;
	string ans="";
	for(int i=0; i<n; i++) {
		seen.insert(s[i]);
		if(seen.size()==4) {
			ans+=s[i];
			seen.clear();
		}
	}
	cout << ans;
	if(!seen.count('A')) {
		cout << 'A';
	} else if(!seen.count('G')) {
		cout << 'G';
	} else if(!seen.count('C')) {
		cout << 'C';
	} else {
		cout << 'T';
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