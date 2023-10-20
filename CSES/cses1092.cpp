#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main () {
    ll n;
    cin >> n;
    ll sum = n*(n+1)/2;
    if (sum%2==0) {
        vector<ll> v1;
        vector<ll> v2;
        if (n%2){
            for (ll i = 1; i <= (n-3)/2; i+=2) {
                v1.push_back(i); v1.push_back(n-i);
                v2.push_back(i+1); v2.push_back(n-i-1);
            }
            v1.push_back(n/2); v1.push_back(n/2 + 1);
            v2.push_back(n);
        }
        else {
            for (ll i = 1; i <= n/2; i+=2) {
                v1.push_back(i); v1.push_back(n+1-i);
                v2.push_back(i+1); v2.push_back(n-i);
            }
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        cout << "YES" << '\n';
        cout << v1.size() << '\n';
        for (auto it: v1) cout << it << " ";
        cout << '\n';
        cout << v2.size() << '\n';
        for (auto it: v2) cout << it << " ";
    }
    else cout << "NO";
}