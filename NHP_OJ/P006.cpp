#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<char>> tab(m, vector<char>(n));
    for (auto &i: tab)
        for (auto &j: i) cin >> j;
    vector<string> vec;
    string tmp = "";
    for (auto i: tab){
        tmp = "";
        for (auto j: i){
            if (j != '#') tmp += j;
            else {
                if (tmp.size() > 1){
                    vec.push_back(tmp);
                    tmp = "";
                }
                else{
                    tmp = "";
                    continue;
                }
            }
        }
        if (tmp.size() > 1){
            vec.push_back(tmp);
        }
    }

    tmp = "";
    for (int i = 0; i < n; i++){
        tmp = "";
        for (int j = 0; j < m; j++){
            if (tab[j][i] != '#') tmp += tab[j][i];
            else {
                if (tmp.size() > 1){
                    vec.push_back(tmp);
                    tmp = "";
                }
                else {
                    tmp = "";
                    continue;
                }
            }
        }
        if (tmp.size() > 1){
            vec.push_back(tmp);
        }
    }
    sort(vec.begin(), vec.end());
    cout << vec[0];
}