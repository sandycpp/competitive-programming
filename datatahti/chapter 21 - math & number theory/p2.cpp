#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int M=1e9+7;
int a, b, c;

ll modpow(ll a, ll n, ll m) {
	a%=m;
	ll res=1;
	while(n>0) {
		if(n&1) {
			res=res*a%m;
		}
		a=a*a%m;
		n>>=1;
	}
	return res;
}
 
 
void solve() {
	cin >> a >> b >> c;
	cout << modpow(a, modpow(b, c, M-1), M) << "\n";
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