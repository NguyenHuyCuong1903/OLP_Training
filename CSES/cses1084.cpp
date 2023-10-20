#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    vector<ll> b(m);
    for (auto &it: a) cin >> it;
    for (auto &it: b) cin >> it;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int cnt = 0;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (b[j] < a[i] - k) j++;
        else if (b[j] > a[i] + k) i++;
        else {
            cnt++, i++, j++;
        }
    }
    cout << cnt;
}
