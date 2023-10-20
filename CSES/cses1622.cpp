#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int cnt = 0;
    vector<string> v;
    do {
        v.push_back(s);
        cnt++;
    }while (next_permutation(s.begin(), s.end()));
    cout << cnt << '\n';
    for (auto it: v) cout << it << '\n';
    return 0;
}