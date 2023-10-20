#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n;
    cin >> n;
    int ans = 0;
    while (n) {
        ans += n/5;
        n /= 5;
    }
    cout << ans;
}