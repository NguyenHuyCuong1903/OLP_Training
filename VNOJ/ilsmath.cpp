#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll cnt_num(ll k) {
	double res = 0;
	ll i = 2;
	while (ceil(res)<k){
		res += log((double)i)/log(10);
		i++;
	}
	if (ceil(res)==k) return i-1;
	else return -1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	if (n < 2) {
		cout << 4 << '\n' << 0 << '\n' << 1 << '\n' << 2 << '\n' << 3;
	}
	else if (n == 3) {
		cout << 2 << '\n' << 5 << '\n' << 6;
	}
	else {
		ll k = cnt_num(n);
		if (k==-1) cout << "NO";
		else cout << 1 << '\n' << k;
	}
}