#include <bits/stdc++.h>
using namespace std;

void rvZero(string &s){
    while (s[0] == '0') s.erase(s.begin());
}

int cmp(string s1, string s2){
    if (s1.length() < s2.length()) return -1;
    else if (s1.length() > s2.length()) return 1;
    else {
        for (int i = 0; i < s1.length(); i++){
            if (s1[i] < s2[i]) return -1;
            else if (s1[i] > s2[i]) return 1;
            else continue;
        }
    }
    return 0;
}

int cmp2(string s1, string s2){
    if (s1[0] == '-' && s2[0] != '-') return -1;
    else if (s1[0] != '-' && s2[0] == '-') return 1;
    else if (s1[0] != '-' && s2[0] != '-') return cmp(s1, s2);
    else {
        int sz1 = s1.length(), sz2 = s2.length();
        if (cmp(s1.substr(1, sz1-1), s2.substr(1, sz2-1)) > 0) return -1;
        else if (cmp(s1.substr(1, sz1-1), s2.substr(1, sz2-1)) < 0) return 1;
        return 0;
    }
}

int main(){
    int n;
    cin >> n;
    string res = "";
    for (int i = 0; i < 1000; i++) res += '9';
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        rvZero(s);
        if (cmp2(s, res) < 0) res = s;
    }
    cout << res;
}