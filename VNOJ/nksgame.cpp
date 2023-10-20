
#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<ll> b(n), c(n);
	for (auto &it : b) cin >> it;
	for (auto &it : c) cin >> it;
	sort(c.begin(), c.end());
	ll res = INT_MAX;
	for (auto it: b) {
		int id = lower_bound(c.begin(), c.end(), -it) - c.begin();
		ll min_tmp = abs(c[id-1] + it);
		if (id < n) {
			if (abs(c[id] + it) < min_tmp) min_tmp = abs(c[id] + it);
		}
		if (id < n-1) {
			if (abs(c[id+1] + it) < min_tmp) min_tmp = abs(c[id+1] + it);
		}
		if (min_tmp < res) res = min_tmp;
	}
	cout << res;
}