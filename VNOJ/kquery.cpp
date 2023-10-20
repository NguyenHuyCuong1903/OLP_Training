#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll, ll>


const ll maxN = 500000;
struct dt {
    ll i, j, type, id;
    ll k;
};

dt a[maxN];
int BIT[maxN], res[maxN];
int n;

bool cmp (dt a, dt b) {
    return a.k > b.k || (a.k == b.k && a.type > b.type);
}

void update (ll x) {
    while (x <= n) {
        BIT[x]++;
        x += x&-x;
    }
}

ll get(ll x) {
    int ans = 0;
    while (x > 0) {
        ans += BIT[x];
        x -= x&-x;
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].k;
        a[i].i = a[i].j = i;
        a[i].type = -1;
    }
    ll q; cin >> q;
    for (ll i = 1; i <= q; i++) {
        cin >> a[i+n].i >> a[i+n].j >> a[i+n].k;
        a[i+n].id = i;
    }
    sort(a+1, a+n+q+1, &cmp);
    for (ll i = 1; i <= n+q; i++) {
        if (a[i].type == -1) update(a[i].i);
        else res[a[i].id] = get(a[i].j) - get(a[i].i - 1);
    }
    for (ll i = 1; i <= q; i++) {
        cout << res[i] << '\n';
    }
}