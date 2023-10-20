#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define maxn 100001
ll a[maxn], st[4*maxn];

void build(ll id, ll l, ll r) {
    if (l==r) {
        st[id] = a[l];
        return;
    }
    ll mid = (l+r)/2;
    build (2*id, l, mid);
    build (2*id+1, mid+1, r);
    st[id] = __gcd(st[2*id], st[2*id+1]);
}

ll getVal (ll id, ll l, ll r, ll u, ll v) {
    if (u > r || v < l) return 0;
    if (l>=u && r<=v) return st[id];
    ll mid = (l+r)/2;
    return __gcd(getVal(id*2, l, mid, u, v), getVal(id*2+1, mid+1, r, u, v));
}

int main () {
    ll n, k;
    cin >> n >> k;
    vector<ll> v1(n), v2(n);
    for (auto &it: v1) cin >> it;
    for (auto &it: v2) cin >> it;
    for (ll i = 1; i <= n; i++) {
        a[i] = __max(v1[i-1], v2[i-1]) - __min(v1[i-1], v2[i-1]);
    }
    build(1, 1, n);
    while (k--) {
        ll l, r;
        cin >> l >> r;
        cout << getVal(1, 1, n, l, r) << '\n';
    }
}