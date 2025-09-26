#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimization("Ofast,unroll-loops")
 
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define se second
#define fi first
 
vector<string> s;
int n, m, ans=0;
 
void dfs(int i, int j) {
    s[i][j] = '#';
    if(i>0 && s[i-1][j]=='.')
        dfs(i-1, j);
    if(i<n-1 && s[i+1][j]=='.')
        dfs(i+1, j);
    if(j>0 && s[i][j-1]=='.')
        dfs(i, j-1);
    if(j<m-1 && s[i][j+1]=='.')
        dfs(i, j+1);
}
 
void solve() {
    cin >> n >> m;
    s.resize(n);
    for(int i=0; i<n; i++) {
        cin >> s[i];
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(s[i][j]=='.') {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans;
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