#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n;
    cin >> n;
    set<int> a;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }
    cout << a.size();
    return 0;
}
