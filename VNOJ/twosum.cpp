#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> v(5001, 0);


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int ans = 0;
    for (int k = 1; k < n; k++) {
		int i = k, j = k + 1;
		ll sum_i = v[i], sum_j = v[j];
		while (i >= 1 && j <= n) {
			if (sum_i == sum_j){
				if (ans < j-i+1) {
					ans = j-i+1;
				}
				++j;
				--i;
				if (i >= 1)
					sum_i += v[i];
				if (j <= n)
					sum_j += v[j];
			}
			else if (sum_i < sum_j) {
				--i;
				if (i >= 1)
					sum_i += v[i];
			}
			else {
				++j;
				if (j <= n)
					sum_j += v[j];
			}
		}
	}
    cout << ans;
}