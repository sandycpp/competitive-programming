#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define debug(x) cout << (x) << "\n"
#define pb push_back
#define ar array
 
string s;
set<string> seen;
 
int main() {
	cin >> s;
	sort(s.begin(), s.end());
	do{ 
		seen.insert(s);
	} while(next_permutation(s.begin(), s.end()));
	cout << seen.size() << "\n";
	for(string a:seen)
		cout << a << "\n";
    return 0;
}
