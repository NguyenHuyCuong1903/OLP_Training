#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n, k;
	
	cin >> n >> k;
	vector<char> s(n);
	for (auto &it: s) cin >> it;
	vector<int> v47;
	ll sz = s.size();
	for (ll i = sz-2; i >= 0; i--){
		if (s[i]=='4' && s[i+1]=='7') v47.push_back(i);
	}
	ll id;
	ll i = 0;
	ll cnt = 0;
	while (i < k){
		if (v47.size()==0) break;
		id = v47.back();
		v47.pop_back();
		if (id%2==1) {
			s[id] = '7';
			if (s[id-1]!='4') cnt++;
			if (s[id-1]=='4') {
				if ((k-cnt)%2==0)
					s[id] = '4';
				else s[id] = '7';
				break;
			}
		}
		else {	
			s[id+1] = '4';
			if (s[id+2]!='7') cnt++;
			if (s[id+2]=='7') {
				if ((k-cnt)%2==0)
					s[id+1] = '7';
				else s[id+1] = '4';
				break;
			}
		}
		i++;
	}
	for (auto it: s) cout << it;
}
