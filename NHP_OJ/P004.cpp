#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    vector<int> chess_in(6);
    vector<int> chess{1, 1, 2, 2, 2, 8};
    for (auto &item: chess_in) cin >> item;
    for (int i = 0; i < 6; i++) cout << chess[i] - chess_in[i] << " ";
}