#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cout << (x) << "\n"
#define ll long long
#define ar array
#define pb push_back
#define pf push_front
 
int n;
 
void solve() {
	cin >> n;
	vector<ar<int, 3>> customers(n);
	for(int i=0; i<n; i++) {
		cin >> customers[i][0] >> customers[i][1];
		customers[i][2]=i;
	}
 
	sort(customers.begin(), customers.end());
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int room=1;
	vector<ar<int, 2>> ans;
	for(int i=0; i<n; i++) {
		if(pq.empty()) {
			pq.push({customers[i][1], room});
			ans.pb({customers[i][2], room});
			room++;
			continue;
		}
		
		int curRoom=pq.top().second;
		int curLeave=pq.top().first;
 
		if(curLeave<customers[i][0]) {
			pq.pop();
			pq.push({customers[i][1], curRoom});
			ans.pb({customers[i][2], curRoom});
		} else {
			pq.push({customers[i][1], room});
			ans.pb({customers[i][2], room});
			room++;
		}
	}
	sort(ans.begin(), ans.end());
	cout << room-1 << "\n";
	for(int i=0; i<n; i++) {
		cout << ans[i][1] << " ";
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