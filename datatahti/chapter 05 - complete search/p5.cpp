#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cout << (x) << "\n"
#define ll long long
#define ar array
#define pb push_back
#define pf push_front
 
int ans=0;
string s;
bool vis[7][7];
 
void search(int i, int j, int c) {
	if(c==48 && j==0 && i==6) {
		ans++;
		return;
	}
	//optimizations
	//reaching endpoint early
	if(j==0 && i==6) {
		return;
	}
	//splitting search field into 2 early
	
	//touching upper or lower wall early
	if(((i==0||i==6) && j>0 && j<6) && !vis[i][j-1] && !vis[i][j+1]) {
		return;
	}
	//touching left or right wall early
	if(((j==0||j==6) && i>0 && i<6) && !vis[i+1][j] && !vis[i-1][j]) {
		return;
	}
	// if up and down are visited but not right or left
	if((i>0 && j>0 && i<6 && j<6)&&vis[i+1][j] && vis[i-1][j] && !vis[i][j+1] && !vis[i][j-1]) {
		return;
	}
	// if left and right visited but not up and down
	if((i>0 && j>0 && i<6 && j<6)&&vis[i][j+1] && vis[i][j-1] && !vis[i-1][j] && !vis[i+1][j]) {
		return;
	}
	//right
	if(j<6 && !vis[i][j+1] && (s[c]=='?' || s[c]=='O')) {
		vis[i][j+1]=1;
		search(i, j+1, c+1);
		vis[i][j+1]=0;
	}
	//down
	if(i<6 && !vis[i+1][j] && (s[c]=='?' || s[c]=='A')) {
		vis[i+1][j]=1;
		search(i+1, j, c+1);
		vis[i+1][j]=0;
	}
	//left
	if(j>0 && !vis[i][j-1] && (s[c]=='?' || s[c]=='V')) {
		vis[i][j-1]=1;
		search(i, j-1, c+1);
		vis[i][j-1]=0;
	}
	//up
	if(i>0 && !vis[i-1][j] && (s[c]=='?' || s[c]=='Y')) {
		vis[i-1][j]=1;
		search(i-1, j, c+1);
		vis[i-1][j]=0;
	}
}
 
int main() {
	cin >> s;
	vis[0][0]=1;
	if(s[0]=='Y' || s[0]=='V') {
		cout << 0 << "\n";
		return;
	}
	search(0, 0, 0);
	cout << ans << "\n";
    return 0;
}
 