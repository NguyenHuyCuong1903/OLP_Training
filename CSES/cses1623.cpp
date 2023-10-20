#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
ll a[20];

ll min(ll a, ll b) {
    return a < b ? a : b;
}

void backtrack (int i, ll &res, ll sum, ll tmp) {
    for (int j = 0; j <= 1; j++) {
        tmp += a[i]*j;
        if (i==n-1) {
            res = min(res, abs(2*tmp - sum));
        }
        else backtrack(i+1, res, sum, tmp);
        tmp -= a[i]*j;
    }
}


int main() {
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    ll res = LLONG_MAX;
    ll tmp = 0;
    backtrack(0, res, sum, tmp);
    cout << res;
}