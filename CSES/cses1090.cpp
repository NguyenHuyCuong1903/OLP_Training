#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, x;
    cin >> n >> x;
    vector<ll> w(n);
    for (auto &it: w) cin >> it;
    sort(w.begin(), w.end());
    ll i = 0, j = n-1;
    ll cnt = 0;
    while (i < n && j >= 0 && i <= j) {
        if (w[i] + w[j] > x) {
            cnt++;
            j--;
        }
        else {
            cnt++;
            i++;
            j--;
        }
    }
    cout << cnt;
}