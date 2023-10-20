#include <bits/stdc++.h>
using namespace std;
#define ll long long

int arr[16];
int n;
vector<string> v;

void print_bit(int n) {
    string s = "";
    for (int i = n; i > 0; i--) {
        s += to_string(arr[i]);
    }
    v.push_back(s);
}

void binary_bit(int k) {
    if (k==0) {
        print_bit(n);
        return;
    }
    arr[k] = 0; binary_bit(k-1);
    arr[k] = 1; binary_bit(k-1);
}

bool check (string b1, string b2) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (b1[i] != b2[i]) cnt++;
    }
    return cnt == 1;
}


int main() {
    cin >> n;
    binary_bit(n);
    vector<bool> visited(pow(2, n), false);
    visited[0] = true;
    cout << v[0] << '\n';
    string tmp = v[0];
    for (int i = 1; i < pow(2, n); i++) {
        for (int j = 1; j < pow(2, n); j++) {
            if (check(tmp, v[j]) && !visited[j]) {
                cout << v[j] << '\n';
                tmp = v[j];
                visited[j] = true;
            }
        }
    }
}