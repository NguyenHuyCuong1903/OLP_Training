#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int base = 31;
const ll MOD = 1000000003;
const ll maxn = 200000;

using namespace std;

ll POW[maxn], hashT[maxn], hashP[maxn];


ll getHashT(ll i,ll j) {
    return (hashT[j] - hashT[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}

ll getHashP(ll i,ll j) {
    return (hashP[j] - hashP[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Input
    string T, P;
    cin >> P >> T;

    // Initialize
    ll lenT = T.size(), lenP = P.size();
    T = " " + T;
    P = " " + P;
    POW[0] = 1;

    // Precalculate base^i
    for (ll i = 1; i <= lenT; i++)
    	POW[i] = (POW[i - 1] * base) % MOD;

    // Calculate hash value of T[1..i]
    for (ll i = 1; i <= lenT; i++)
    	hashT[i] = (hashT[i - 1] * base + T[i] - 'a' + 1) % MOD;

    // Calculate hash value of P
    for (ll i = 1; i <= lenT; i++)
    	hashP[i] = (hashP[i - 1] * base + P[i] - 'a' + 1) % MOD;

    // Finding substrings of T equal to string P
    // for (int i = 1; i <= lenT - lenP + 1; i++)
    // 	if (hashP == getHashT(i, i + lenP - 1))
    // 		printf("%d ", i);
    ll q;
    cin >> q;
    while (q--) {
        ll i, j, u, v;
        cin >> i >> j >> u >> v;
        ll cnt = 0;
        for (ll k = u; k <= v + i - j; k++)
    	if (getHashP(i, j) == getHashT(k, k + j - i))
    		cnt++;
        cout << cnt << '\n';
    }
}