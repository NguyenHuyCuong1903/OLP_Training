#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(pair<ll, ll> a, pair<ll, ll> b){
    return a.first + a.second < b.first + b.second || (a.first + a.second == b.first + b.second && a.first < b.first);
}

vector<ll> square;
pair<ll, ll> task(ll s, ll h, ll w){
    ll x, y;
    vector<pair<ll, ll>> v;
    for (ll i = 0; i <= 500; i++){
        for (ll it: square){
            x = it;
            y = (s + i) - x;
            if (y == x || (x == h*h && y == w*w)|| x >= y || (x+y==s && sqrt(x) <= h)) continue;
            int id = lower_bound(square.begin(), square.end(), y) - square.begin();
            if (y == square[id]) v.push_back({x, y});
        }
    }
    sort(v.begin(), v.end(), &cmp);
    return {(int)sqrt(v[0].first), (int)sqrt(v[0].second)};
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int h = 1, w = 1;
    for (ll i = 1; i <= 1000; i++){
        square.push_back(i*i);
    }
    while (h && w){
        cin >> h >> w;
        if (!h && !w) break;
        pair<ll, ll> tmp = task(h*h+w*w, h, w);
        cout << tmp.first << " " << tmp.second << '\n';
    }
}