#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long d;
    cin >> d;
    long long minV = d;
    long long maxV = INT_MIN;
    for (int i = 1;  i < n; i++){
        cin >> d;
        maxV = max(maxV, d - minV);
        minV = min(minV, d);
    }
    cout << maxV;
}