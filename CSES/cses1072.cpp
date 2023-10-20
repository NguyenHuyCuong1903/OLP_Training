#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(ll k) {
    return (k*k*(k*k-1))/2 - 4*(k-1)*(k-2);
}

int main () {
    int n;
    cin >> n;
    cout << 0 << '\n';
    for (int i = 2; i <= n; i++) {
        cout << solve(i) << '\n';
    }
}