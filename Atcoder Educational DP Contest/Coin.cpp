#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;  cin >> n;
    vector<long double> p(n+1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    vector<vector<long double>> F(n+1, vector<long double>(n+1, 0));
    F[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        F[i][0] = F[i-1][0]*(1-p[i]);
    }
    F[1][1] = p[1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            F[i][j] = F[i-1][j-1]*p[i] + F[i-1][j]*(1-p[i]);
        }
    }
    double ans = 0;
    for (int i = n/2 + 1; i <= n; i++) {
        ans += F[n][i];
    }
    printf("%.9lf", ans);
}