#include <bits/stdc++.h>
using namespace std;

const int inf  = 1e9 + 7;
const int maxN = 1e5 + 7;

int a[maxN];
long long st[4 * maxN];

int ucln(int a, int b){
    if (b == 0) return a;
    if (a % b == 0) return b;
    return ucln(b, a%b);
}

void build(long long id, int l, int r){
    // nút lá
    if (l==r){
        st[id] = a[l];
        return;
    }

    int mid = (l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);

    st[id] = st[id*2] + st[id*2+1];
}

void update(long long id, int l, int r, int i, int val){
    if (i<l || i>r) return;
    if (l==r){
        st[id] = val;
        return;
    }

    int mid = (l+r)/2;
    update(id*2, l, mid, i, val);
    update(id*2+1, mid+1, r, i, val);

    st[id] = st[id*2] + st[id*2+1];
}

long long getVal(long long id, int l, int r, int u, int v){
    if (l>v || r<u) return 0;
    if (l>=u && r<=v) return st[id];
    
    int mid = (l+r)/2;
    long long v1 = getVal(id*2, l, mid, u, v);
    long long v2 = getVal(id*2+1, mid+1, r, u, v);
    return v1 + v2;
}

int main(){
    int n, q;
    long long x;
    cin >> n >> x >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1, 1, n);
    int cnt = 0;
    for (int i = 0; i < q; i++){
        int u, v;
        cin >> u >> v;
        if (getVal(1, 1, n, u, v) < x){
            cnt++;
        }
        
    }
    cout << cnt;
}