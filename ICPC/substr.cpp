#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int max_n = 1000000;
const int base = 31;
ll MOD = 1000000007;
ll hashT[max_n], Pow[max_n];


ll getHash(ll i, ll j){
    return (hashT[j] - hashT[i-1]*Pow[j-i+1] + MOD*MOD) % MOD;
}

int main(){
    string T, P;
    cin >> T >> P;
    ll lenT = T.length();
    ll lenP = P.length();
    T = " " + T;
    P = " " + P;
    Pow[0] = 1;
    for (ll i = 1; i <= lenT; i++){
        Pow[i] = Pow[i-1]*base % MOD;
    }

    hashT[0] = 1;
    for (ll i = 1; i <= lenT; i++){
        hashT[i] = (hashT[i-1]*base + T[i] - 'a' + 1) % MOD;
    }

    ll hashP = 0;
    for (ll i = 1; i <= lenP; i++){
        hashP = (hashP*base + P[i] - 'a' + 1) % MOD;
    }
    int cnt = 0;
    for (ll i = 1; i <= lenT-lenP+1; i++){
        if (hashP == getHash(i, lenP + i - 1))
            cnt++;
    }
    cout << cnt;
}