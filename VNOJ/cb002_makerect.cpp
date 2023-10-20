#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<ll, ll> M;

bool cmp(ll x, ll y){
    return x > y;
}

int main(){
    ll N;
    vector<ll> v;
    cin >> N;
    for (int i = 0; i < N; i++){
        ll d;
        cin >> d;
        if (!M.count(d)) M[d] = 1;
        else M[d]++;
    }
    for (auto i : M){
        if (i.second > 1) v.push_back(i.first);
        if (i.second >= 4) v.push_back(i.first);
    }
        
    if (v.size() < 2) {
        cout << 0;
        return 0;
    }
    sort(v.begin(), v.end(), &cmp);
    cout << v[0]*v[1];
    return 0;
}