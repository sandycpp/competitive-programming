#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define se second
#define fi first
 
ll dp[51];
 
void solve() {
    int n;
    cin >> n;
    dp[0]=1;
    for(int i=0; i<n; i++) {
        for(int j=1; j<7; j++) {
            if(i+j<=n) {
                dp[i+j]+=dp[i];
            }
        }
    }
    cout << dp[n];
}
 
int main() {
    //freopen("breedflip.in", "r", stdin);
    //freopen("breedflip.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}