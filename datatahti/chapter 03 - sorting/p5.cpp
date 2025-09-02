#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define debug(x) cout << (x) << "\n"
#define pb push_back
#define ar array
 
const int mxN=1e5;
int n, a[mxN];
 
void solve() {
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	int c=0;
	for(int i=n-1; i>=0; i--) {
		if(a[i]==n-c) c++;
	}
	cout << n-c;
}
 
int main() {
	int T=1;
	//cin >> T;
	while(T--)
		solve();
	return 0;
}
