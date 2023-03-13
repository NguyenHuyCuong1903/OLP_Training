#include<bits/stdc++.h>
using namespace std;
#define ll long long

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll t;  cin >> t;
    while (t--) {
        int x,y; ll a;
        cin >> x >> y >> a;
        cout << (a/(x+y) * x) * 5 + min(a%(x+y), x) * 5 << '\n';
    }
    return 0;
}