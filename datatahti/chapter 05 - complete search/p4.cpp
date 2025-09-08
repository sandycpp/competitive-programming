#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cout << (x) << "\n"
#define ll long long
#define ar array
#define pb push_back
#define pf push_front
 
const int mxN=8;
int n, m, ans=0;
bool board[mxN][mxN];
 
void search() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(!board[i][j]) {
				// current + down + down-left
				if(i+1<n && j>0 && !board[i+1][j] && !board[i+1][j-1]) {
					board[i][j] = board[i+1][j] = board[i+1][j-1] = 1;
					search();
					board[i][j] = board[i+1][j] = board[i+1][j-1] = 0;
				}
				// current + down + down-right
				if(i+1<n && j+1<m && !board[i+1][j] && !board[i+1][j+1]) {
					board[i][j] = board[i+1][j] = board[i+1][j+1] = 1;
					search();
					board[i][j] = board[i+1][j] = board[i+1][j+1] = 0;
				}
				// current + right + down-right
				if(i+1<n && j+1<m && !board[i][j+1] && !board[i+1][j+1]) {
					board[i][j] = board[i][j+1] = board[i+1][j+1] = 1;
					search();
					board[i][j] = board[i][j+1] = board[i+1][j+1] = 0;
				}
				// current + right + down
				if(i+1<n && j+1<m && !board[i][j+1] && !board[i+1][j]) {
					board[i][j] = board[i][j+1] = board[i+1][j] = 1;
					search();
					board[i][j] = board[i][j+1] = board[i+1][j] = 0;
				}
				return;
			}
		}
	}
	ans++;
}
 
int main() {
	cin >> n >> m;
	search();
	cout << ans << "\n";
    return 0;
}
 
