#include <bits/stdc++.h>
using namespace std;

long long F[2001][2002];
long long process(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    for (int i = 0; i < n; i++)
        F[0][1] = 0;
    for (int i = 0; i < m; i++)
        F[i][0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (s1[i] == s2[j])
                F[i][j] = F[i-1][j-1] + 1;
            else
                F[i][j] = max(F[i-1][j], F[i][j-1]);
        }
    }
    return F[n-1][m-1];
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    s1 = ' ' + s1;
    s2 = ' ' + s2;
    cout << process(s1, s2) << endl;
}