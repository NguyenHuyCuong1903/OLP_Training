#include<bits/stdc++.h>
using namespace std;


int main() {
    long long n;
    cin >> n;
    long long k = sqrt(n*2);
    if (k*(k+1) == n*2) cout << "YES";
    else cout << "NO";
    return 0;
}