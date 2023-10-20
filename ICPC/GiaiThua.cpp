#include<bits/stdc++.h>
using namespace std;


	
const int d[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};
long long f[20];

int D(long long n) {
	if(n < 10) return d[n];
	if (n%100/10 % 2 == 0) return 6*D(n/5)*D(n%10)%10;
    else return 4*D(n/5)*D(n%10)%10;
}

void factory(int n){
    f[0] = 1;
    for (int i = 1; i <= n; i++){
        f[i] = f[i-1]*i;
    }
}

int main() {
	int t, n;
    cin >> t;
    factory(19);
    for (int i = 0; i < t; i++){
        cin >> n;
        cout << f[n] << endl;
    }
}