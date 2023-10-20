#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(ll y, ll x) {
    if (y <= x) {
        if (x%2) return x*x - y + 1;
        else return (x-1)*(x-1) + 1 + y - 1;
    }
    else {
        if (y%2) return (y-1)*(y-1) + 1 + x - 1;
        else return y*y - x + 1;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--) {
        ll y, x;
        cin >> y >> x;
        cout << solve(y, x) << '\n';
    }
}