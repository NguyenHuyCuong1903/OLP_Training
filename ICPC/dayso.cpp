#include<bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	vector<long long> v;
	long long d;
	for (int i = 0; i < n; i++) {
		cin >> d;
		v.push_back(d);
	}

	long long res = INT_MIN;
	vector<long long> vec;
	vec.resize(3);
	for (int i = 2; i < n; i++) {
        long long tmp = v[i] + v[i-1] + v[i-2];
		vec[(i+1)%3] = max(tmp, vec[(i+1)%3] + tmp);
        res = max(res, vec[(i+1)%3]);
	}
	cout << res;
}