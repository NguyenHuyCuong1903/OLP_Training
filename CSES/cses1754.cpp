#include <bits/stdc++.h>
using namespace std;
#define ll long long


bool check(ll a, ll b) {
    if (a/2 > b || b/2 > a) return false;
    if ((a+b)%3==0) return true;
    return false;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (check(a, b)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}