#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll, ll>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) {
        ll d; cin >> d;
        v[i] = d%k;
    }
    /*
        F(i, j) độ dài dãy con dài nhất tính đến phần tử thứ i chia k dư j
        CT QHD: F(i,j) = max(F(i-1, j), F(i-1, (j-a[i]+k)%k) + 1)
    */

    vector<vector<int>> F(n+1, vector<int>(k));
    for (int i = 1; i < k; i++) F[1][i] = INT_MIN;
    F[1][v[1]] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            F[i][j] = max(F[i-1][j], 1 + F[i-1][(j-v[i]+k)%k]);
        }
    }
    cout << F[n][0];
}