#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll ans = 0;
    ll prenum = 0;
    while (n--) {
        ll d;
        cin >> d;
        if (d < prenum) ans += prenum - d;
        else prenum = d;
    }
    cout << ans;
}