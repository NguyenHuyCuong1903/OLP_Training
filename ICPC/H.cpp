#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll MOD = 10e9+7;

ll powmod(int a, ll n) {
    if (!n) return 1;
    ll k = powmod(a, n/2)%MOD;
    if (n%2) return (k*k*a)%MOD;
    else return (k*k)%MOD;
}

int cmp(string s1, string s2) {
    if (s1.length() < s2.length()) return -1;
    else if (s1.length() > s2.length()) return 1;
    else {
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i]-'0' < s2[i]-'0') return -1;
            else if (s1[i]-'0' > s2[i]-'0') return 1;
        }
    }
    return 0;
}

int max2digits(int a, int b) {
    int ans = 0;
    for (int i = a; i <= b; i++) {
        if (i >= 10){
            if (ans < (i%10)*(i/10)) ans = (i%10)*(i/10);
        }
        else {
            if (ans < i) ans = i;
        }
    }
    return ans;
}

bool check_last_9 (string s, ll i, ll j) {
    for (ll it = i; it <= j; it++) {
        if (s[it] != '9') return false;
    }
    return true;
}

ll process(string l, string r) {
    ll ans;
    if (l.length()==r.length()) {
        ll same = 0;
        for (ll i = 0; i < r.length(); i++) {
            if (l[i]==r[i]) same++;
            else break;
        }
        ll numdigits_9 = r.length() - same - 2;
        if (numdigits_9 > 0)
            ans = powmod(9, numdigits_9);
        else ans = powmod(9, 0);
        for (ll i = 0; i < same; i++) {
            ans = (ans*(r[i]-'0'))%MOD;
        }
        if (same + 3 < r.length()) {
            if (check_last_9(r, same+2, r.length()-1)) ans = (ans*max2digits( (l[same]-'0')*10+(l[same+1]-'0'), (r[same]-'0')*10+(r[same+1]-'0' )))%MOD;
            else ans = (ans*max2digits( (l[same]-'0')*10+(l[same+1]-'0'), (r[same]-'0')*10+(r[same+1]-'0')-1))%MOD;
        }
        else ans = (ans*max2digits( (l[same]-'0')*10+(l[same+1]-'0'), (r[same]-'0')*10+(r[same+1]-'0' )))%MOD;
    }
    else {
        ll numdigits_9 = r.length() - 2;
        ans = powmod(9, numdigits_9);
        if (r.length() > 2) {
            if (check_last_9(r, 2, r.length()-1)){
                ans = (ans*max2digits(9, (r[0]-'0')*10+(r[1]-'0')))%MOD;
            }
            else {
                ans = (ans*max2digits(9, (r[0]-'0')*10+(r[1]-'0')-1))%MOD;
            }
        }
        else ans = (ans*max2digits(9, (r[0]-'0')*10+(r[1]-'0')))%MOD;
    }
    return ans;
}


// Driver Code
int main()
{
    string l, r;
    cin >> l >> r;
    if (r.length() == 1) cout << r;
    else cout << process(l, r);
    return 0;
}