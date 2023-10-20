#include <bits/stdc++.h>
using namespace std;

long long process(long long n){
    long long res = 0;
    while (n > 0){
        res += n/2;
        n /= 2;
    }
    return res;
}

int main(){
    long long l, r;
    cin >> l >> r;
    cout << process(r) - process(l-1);
}