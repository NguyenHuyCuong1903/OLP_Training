#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll MOD = 1000000007;

ll powmod(ll a, ll n) {
    if (n==0) return 1;
    ll t = powmod(a, n/2)%MOD;
    if (n%2) return (t*t*a)%MOD;
    else return (t*t)%MOD;
}

int main () {
    ll n;
    cin >> n;
    cout << powmod(2, n);
}