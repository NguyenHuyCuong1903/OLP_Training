#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll maxN = 200001;

vector<ll> F(maxN, 0);
vector<ll> st(maxN*4, 0);

ll max(ll a, ll b) {
    return a > b ? a : b;
}

void update(ll id, ll l, ll r, ll i, ll val) {
    if (l > i || r < i) return;
    
    if (l == r) {
        st[id] = val;
        return;
    }
    
    ll mid = l + r >> 1;
    update(2 * id, l, mid, i, val);
    update(2 * id + 1, mid + 1, r, i, val);
    
    st[id] = max(st[2 * id], st[2 * id + 1]);
}


ll getVal(ll id, ll l, ll r, ll u, ll v) {

    if (l >  v || r <  u) return INT_MIN; 
    
    if (l >= u && r <= v) return st[id];

    ll mid = l + r >> 1; // (l + r) / 2
    ll get1 = getVal(2 * id, l, mid, u, v);
    ll get2 = getVal(2 * id + 1, mid + 1, r, u, v);
    
    return max(get1, get2);
}

int main() {
    ll n; cin >> n;
    vector<ll> h(n+1);
    vector<ll> a(n+1);
    for (ll i = 1; i <= n; i++) cin >> h[i];
    for (ll i = 1; i <= n; i++) cin >> a[i];

    F[1] = a[1];
    update(1, 1, n, h[1], F[1]);
    ll ans = F[1];
    for (ll i = 2; i <= n; i++) {
        F[i] = getVal(1, 1, n, 1, h[i]) + a[i];
        update(1, 1, n, h[i], F[i]);
        ans = max(ans, F[i]);
    }
    cout << ans;
}