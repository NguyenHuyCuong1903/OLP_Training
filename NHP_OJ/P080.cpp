#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll M = 998244353;
map<ll, ll> F;

ll f(ll n){
    if (F.count(n)==1) return F[n]%M;
    ll k  = n/2;
    if (n%2==0) return F[n] = (f(k)*f(k) + f(k-1)*f(k-1))%M;
    else return F[n] = (f(k)*f(k+1) + f(k)*f(k-1))%M;
}

int main(){
    ll n;
    cin >> n;
    F[0] = 1, F[1] = 1;
    cout << f(n)*f(n+1)%M;
}