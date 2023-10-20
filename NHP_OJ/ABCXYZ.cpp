#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, a, b, c;
int condition1(ll x, ll y, ll z){
    return x+y+z == a;
}

bool condition3(ll x, ll y, ll z){
    return x*x + y*y + z*z == c;
}

vector<ll> divisor(ll b){
    vector<ll> v;
    double k = sqrt(b);
    for (ll i = 1; i <= k; i++){
        if (b % i == 0){
            v.push_back(i);
            v.push_back(-i);
            v.push_back(b/i);
            v.push_back(-b/i);
        }
    }
    sort(v.begin(), v.end());
    return v;
}

int main(){
    cin >> n;
    cin >> a >> b >> c;
    vector<ll> v = divisor(abs(b));
    if (b==0) {
        for (int i = 0; i <= n; i++){
            ll x = i, y = a - x, z = 0;
            if (condition1(x, y, z) && condition3(x, y, z)){
                cout << x << " " << y << " " << z  << '\n';
                return 0;
            }
        }
    }
    for (ll i = 0; i < v.size(); i++){
        for (ll j = 0; j < v.size(); j++){
            ll x= v[i], y = v[j], z = b/(x*y);
            if (x*y*z == b && abs(x) <= n && abs(y) <= n && abs(z) <= n) {
                if (condition1(x, y, z) && condition3(x, y, z)){
                    cout << x << " " << y << " " << z  << '\n';
                    return 0;
                }
            }
        }
    }
}