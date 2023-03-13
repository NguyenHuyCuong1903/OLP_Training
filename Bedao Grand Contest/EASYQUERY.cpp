#include<bits/stdc++.h>
using namespace std;
#define MAXN 200000
#define ll long long

typedef struct {
    ll lazy;
    ll val;
}Node;

Node nodes[MAXN*4];
ll a[MAXN];

void build(ll id, ll l, ll r) {
    if (l==r) {
        nodes[id].val = a[l];
        nodes[id].lazy = 0;
        return;
    }
    ll mid = (l+r)/2;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);
    
    nodes[id].val = nodes[id*2].val + nodes[id*2+1].val;
}

void down(ll id, ll l, ll r) {
    ll t = nodes[id].lazy;
    ll mid = (l+r)/2;
    nodes[id*2].lazy += t;
    nodes[id*2].val += t*(mid-l+1);

    nodes[id*2+1].lazy += t;
    nodes[id*2+1].val += t*(r-mid);

    nodes[id].lazy = 0;
}

void update(ll id, ll l, ll r, ll u, ll v, ll val) {
    
    if (v < l || r < u) {
        return ;
    }
    if (u <= l && r <= v) {
        nodes[id].val += (r-l+1)*val;
        nodes[id].lazy += val;
        return ;
    }
    ll mid = (l + r) / 2;

    down(id, l, r);

    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);

    nodes[id].val = nodes[id*2].val + nodes[id*2+1].val;
}

ll get(ll id, ll l, ll r, ll u, ll v) {
    
    if (v < l || r < u) {
        return 0;
    }
    if (u <= l && r <= v) {
        return nodes[id].val;
    }
    ll mid = (l + r) / 2;
    down(id, l, r);
    return get(id*2, l, mid, u, v) + get(id*2+1, mid+1, r, u, v);
}

typedef struct {
    ll l, r, x;
}query;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q;
    cin >> n >> q;
    for (ll i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    
    vector<query> Qu = {{0,0,0}};
    while (q--) {
        ll type;   cin >> type;
        if (type==1) {
            ll l, r, x; cin >> l >> r >> x;
            update(1, 1, n, l, r, x);
            Qu.push_back({l,r,x});
        }
        else if (type==2){
            ll x; cin >> x;
            query tmp = Qu[x];
            Qu.push_back({tmp.l, tmp.r, (-1)*tmp.x});
            update(1, 1, n, tmp.l, tmp.r, -tmp.x);
        } else {
            ll u, v; cin >> u >> v;
            Qu.push_back({0,0,0});
            cout << get(1, 1, n, u, v) << '\n';
        }
    }
    return 0;
}