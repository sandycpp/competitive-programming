#include <bits/stdc++.h>
using namespace std;

#define ll long long
 
const int M=1e9+7;
int a, b;

ll modpow(ll a, ll n) {
	a%=M;
	ll res=1;
	while(n>0) {
		if(n&1) {
			res=res*a%M;
		}
		a=a*a%M;
		n>>=1;
	}
	return res;
}
 
void solve() {
	cin >> a >> b;
	cout << modpow(a, b) << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int T=1;
    cin >> T;
	while(T--)
		solve();
    return 0;
}