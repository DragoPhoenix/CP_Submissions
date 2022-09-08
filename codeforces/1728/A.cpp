#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x = 0, y;
    cin>>n;
    vector<int> v1(n);
    

    for (int i=0;i<n;i++) {
        cin >> v1[i];
        if(v1[i] > x)
        {
            x = v1[i];
            y = i + 1;
        }
    }
    cout << y << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
