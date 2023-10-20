#include <bits/stdc++.h>
using namespace std;

long long C(int k, int n){
    long long res = 1;
    for (int i = 1; i <= k; i++, n--){
        res = res * n / i % 1000000007;
    }
    return res;
}

int main(){
    int n, k;
    cin >> n >> k;
    cout << C(k, n);
}