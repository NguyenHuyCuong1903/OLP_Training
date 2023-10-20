#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll min(ll a, ll b) {
    return a < b ? a : b;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll s;
    cin >> n >> s;
    vector<int> v(n);
    for (auto &it: v) cin >> it;
    sort(v.begin(), v.end());
    int ans = 0;
    // greedy
    while (s >= 500) {
        ans += (s/v[n-1])-3;
        s -= ans*v[n-1];
    }

    //QHD
    vector<ll> F(s+1);
    F[0] = 0;
    for (ll i = 1; i <= s; i++) {
        F[i] = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (v[j] <= i) {
                F[i] = min(F[i], F[i-v[j]]+1);
            }
            else break;
        }
    }
    cout << F[s] + ans;
}