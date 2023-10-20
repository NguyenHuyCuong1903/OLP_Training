#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> num(n+1);
    for (ll i = 1; i <= n; i++) cin >> num[i];
    vector<ll> subArr(n+1, 0);
    ll max_sum = 0;
    for (ll i = 1; i <= n; i++) {
        subArr[i] = subArr[i-1] + num[i];
        if (subArr[i] > k){
            subArr[i] = 0;
            ll id = i;
            while (subArr[i] + num[id] <= k) {
                subArr[i] += num[id];
                id--;
            }
        }
        max_sum = fmax(max_sum, subArr[i]);
    }
    cout << max_sum;
}