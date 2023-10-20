#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll max(ll a, ll b) {
    return a > b ? a : b;
}

int main () {
    ll n;
    cin >> n;
    vector<vector<ll>> v(n, vector<ll>(3));
    for (ll i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) 
            cin >> v[i][j];
    }
    vector<vector<ll>> F(n, vector<ll>(3));
    F[0] = {v[0][0], v[0][1], v[0][2]};
    for (ll i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 0) F[i][j] = max(F[i-1][1], F[i-1][2]) + v[i][j];
            if (j == 1) F[i][j] = max(F[i-1][0], F[i-1][2]) + v[i][j];
            if (j == 2) F[i][j] = max(F[i-1][1], F[i-1][0]) + v[i][j];
        }
    }
    ll ans = max(max(F[n-1][0], F[n-1][1]), F[n-1][2]);
    cout << ans;
}