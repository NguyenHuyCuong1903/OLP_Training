#include <bits/stdc++.h>
using namespace std;

double area(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return (0.5) * abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
}

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    double areaS = 0;
    for (int i = 1; i < N; i++){
        areaS += (v[i].first + v[i+1].first) * ();
        cout << tmp << endl;
    }

    // double areaP = 0;
    // for (int i = 0; i < N; i++){
    //     areaP += area(v[i%N].first, v[i%N].second, v[(i+1)%N].first, v[(i+1)%N].second, v[(i+2)%N].first, v[(i+2)%N].second);
    // }

    // double res = areaS*N - areaP;
    // cout << areaS << " " << areaP << endl;
    // if (res == (long long)res) cout << res << ".0";
    // else cout << round(res*10)/10;
}