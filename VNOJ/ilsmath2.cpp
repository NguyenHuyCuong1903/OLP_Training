#include <bits/stdc++.h>
using namespace std;
#define ll long long
double e = 2.718281828;
double pi = 3.141592654;

ll f(ll n) {
	double res = n*log10(n/e) + 0.5*log10(2*pi*n);
	return ceil(res);
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
		ll l = 1, r = 10e9;
		while (l < r) {
			ll mid = (l+r)/2;
			if (f(mid)==n) {
				cout << 1 << '\n' << mid;
				return 0;
			}
			if (f(mid)<n) l = mid+1;
			else r = mid;
		}
		cout << "NO";
		return 0;
	}
}