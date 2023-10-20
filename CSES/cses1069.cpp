#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string s;
    cin >> s;
    ll ans = 0;
    ll len_tmp = 1;
    for (int i = 0; i < s.length()-1; i++)
    {
        if (s[i] != s[i+1]) {
            ans = (ans > len_tmp) ? ans :len_tmp;
            len_tmp = 1;
        }
        else len_tmp++;
    }
    ans = (ans > len_tmp) ? ans :len_tmp;
    cout << ans;
}