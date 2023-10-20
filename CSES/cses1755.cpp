#include <bits/stdc++.h>
using namespace std;
#define ll long long

map<char, int> M;
int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (M.count(s[i])==0) M[s[i]] = 1;
        else M[s[i]]++;
    }
    string ans = "";
    int cnt_odd = 0;
    for (auto [a, b]: M) {
        if (b%2) {
            ++cnt_odd;
            if (cnt_odd > 1) {
                cout << "NO SOLUTION";
                return 0;
            }
            ans.insert(ans.length()/2, b, (char)a);
        }
        else {
            ans.insert(0, b/2, (char)a);
            ans.insert(ans.length(), b/2, (char)a);
        }
    }
    cout << ans;
}