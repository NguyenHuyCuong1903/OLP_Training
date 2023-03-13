#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;    cin >> n >> m >> k;
    if (k <= n || k <= m) {
        for (int i = 1; i <= k; i++) {
            cout << i << " " << i << '\n';
        }
    }
    else {
        cout << n + m + k;
    }
    return 0;
}