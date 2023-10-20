#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    cin >> n;
    int i = 1;
    double res = 0;
    while (i <= n){
        res += 1.0/i;
        i++;
    }
    cout << setprecision(5) << fixed << res ;
    return 0;
}