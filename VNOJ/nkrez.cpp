#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll, ll>

bool cmp(ii a, ii b) {
    return a.first < b.first || a.first == b.first && a.second < b.second;
}

ll max(ll a, ll b) {
    return a > b ? a : b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ii> v(n+1);
    for (ll i = 1; i <= n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), &cmp);
    v[0] = {0, 0};
    vector<ll>F(n+1);
    F[0] = 0;
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        F[i]= 0;
        for (ll j = 0; j < i; j++) {
            if (v[i].first >= v[j].second) F[i] = max(F[i], F[j] + v[i].second - v[i].first);
        }
        ans = max(ans, F[i]);
    }
    cout << ans;
}