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
 
int b[8], ans=0;
string s[8];
 
int main() {
    iota(b, b+8, 0);
    do {
        bool good=1;
        for(int i=0; i<7; i++) {
            for(int j=i+1; j<8; j++) {
                if(abs(i-j)==abs(b[i]-b[j]) || s[b[i]][i]=='*' || s[b[j]][j]=='*') good=0;
            }
        }
        if(good) ans++;
    } while(next_permutation(b, b+8));
    cout << ans;
    return 0;
}
