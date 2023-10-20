#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool cmp (pair<ll, int> a, pair<ll, int> b) {
    return a.first < b.first;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<pair<ll, int>> v;
    for (ll i = 0; i < n; i++) {
        ll s, e;
        cin >> s >> e;
        v.push_back({s, 1});
        v.push_back({e, -1});
    }
    sort(v.begin(), v.end(), &cmp);
    ll ans = 0;
    ll curr = 0;
    for (auto [a, b] : v) {
        curr += b;
        if (b == -1) continue;
        ans = ans > curr ? ans : curr;
    }
    cout << ans;
}