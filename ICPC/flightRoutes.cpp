#include <bits/stdc++.h>
using namespace std;

void flightRoutes(long long n, long long m, long long k,
                  vector<vector<long long>> &arr)
{
    vector<pair<long long, long long>> adj[n + 1];
    for (long long i = 0; i < m; i++)
    {
        long long a = arr[i][0], b = arr[i][1];
        long long w = arr[i][2];

        adj[a].push_back({b, w});
    }
    priority_queue<pair<long long, long long>> q;
    q.push({0, 1});
    long long vis[n + 1] = {0};
    while (!q.empty() && vis[n] < k)
    {
        long long a = q.top().second;
        long long d = q.top().first;
        q.pop();
        vis[a]++;
        if (a == n)
            cout << -d << " ";
        if (vis[a] <= k)
        {
            for (auto tmp : adj[a])
            {
                int b = tmp.first;
                int w = tmp.second;
                q.push({d - w, b});
            }
        }
    }
}

int main(){
    long long n, m, k, u, v, w;
    cin >> n >> m >> k;
    vector<vector<long long>> vec;
    for (int i=0; i<m; i++){
        cin >> u >> v >> w;
        vec.push_back({u, v, w});
    }
    flightRoutes(n, m, k, vec);
}