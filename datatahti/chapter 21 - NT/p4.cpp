#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int mxN=1e6;
int n, divs[mxN+1];
 
void solve() {
	cin >> n;
	while(n--) {
		int a;
		cin >> a;
		for(int i=1; i*i<=a; i++) {
			if(a%i==0) {
				divs[i]++;
				if((i*i)^a) divs[a/i]++;
			}
		}
	}
	for(int i=mxN; i>=0; i--) {
		if(divs[i]>=2) {
			cout << i;
			break;
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
