#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{

    for (;;)
    {
        int n;
        cin >> n;
        if (!n) break;
        vector<char> a(n), b(n), c(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < n; i++) cin >> c[i];
        
        vector<pair<bool, int>> vec(n);

        for (int i = 0; i < n; i++) {
            a[i] -= '0';
            b[i] -= '0';
            c[i] -= '0';

            if ((a[i] + b[i]) % 10 == c[i]) {
                vec[i].first = true;
                vec[i].second = (a[i] + b[i]) % 10;
            } else {
                vec[i].first = false;
                vec[i].second = c[i] - (a[i] + b[i]) % 10;
            }
        }
        vector<int> F(n+1);
        F[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            int id = n;
            for (int j = i + 1; j <= n; j++) {
                if (vec[j])
            }
            if (vec[i].first) F[i] = 
        }
        cout << "";
    }

    return 0;
}