#include<bits/stdc++.h>
using namespace std;
#define ll long long

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n;  cin >> n;
    string s;  cin >> s;
    if (n%2) {
        cout << -1;
        return 0;
    }
    map<char,int> M;
    for (int i = 0; i < n; i++) {
        M[s[i]]++;
    }
    int ans = 0;
    ans = abs(min(M['L'], M['R']) - (M['L'] + M['R'])/2) + abs(min(M['D'], M['U']) - ((M['L'] + M['R'])%2 + M['D'] + M['U'])/2);
    cout << ans;
}