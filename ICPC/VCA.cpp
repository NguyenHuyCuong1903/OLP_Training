#include <bits/stdc++.h>
using namespace std;
long long M = 1000000007;

long long Multiply(vector<long long> vec, long long n, long long k = INT_MAX){
    long long product = 1;
    for (int i = 0; i < n; i++){
        if (vec[i] != k)
        product = (product*vec[i])%M;
    }
    return product;
}

long long process(vector<long long> vec, int n, int cntZero, int cntNegative){
    sort(vec.begin(), vec.end());
    if (cntZero >= 2) return 0;
    if (vec[n-1] == 0){
        if (n%2==0)
            return 0;
        else {
            return Multiply(vec, n-1);
        }
    }
    else if (vec[n-1] < 0){
        if (n%2==0){
            return Multiply(vec, n);
        }
        else {
            return Multiply(vec, n-1);
        }
    }
    else {
        if (cntZero == 1){
            if (cntNegative%2==0){
                return Multiply(vec, n, 0);
            }
            else return 0;
        }
        else {
            if (cntNegative%2==0){
                return Multiply(vec, n);
            }
            else {
                int k = 0;
                for (int i = 0; i<n-1; i++){
                    if(vec[i] < 0 && vec[i+1] > 0)
                    k = i;
                }
                return Multiply(vec, n, vec[k]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long d;
    cin >> n;
    vector<long long> v;
    int cntZero = 0;
    int cntNegative = 0;
    for (int i= 0; i<n; i++){
        cin >> d;
        if (!d) cntZero++;
        if (d < 0) cntNegative++;
        v.push_back(d);
    }
    cout << process(v, n, cntZero, cntNegative);
}