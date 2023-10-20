#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n;
    cin >> n;
    if (n == 3 || n == 2) {
        cout << "NO SOLUTION";
        return 0;
    }
    else {
        for (ll i = 2; i <= n; i+=2) cout << i << " ";
        for (ll i = 1; i <= n; i+=2) cout << i << " ";
    }
}