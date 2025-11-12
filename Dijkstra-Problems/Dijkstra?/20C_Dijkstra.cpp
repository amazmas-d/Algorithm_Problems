#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> g(n+1);
    for (int i = 0; i < m; i++){
        int a,b,w;
        cin >> a >> b >> w;
        g[a].push_back({b,w});
        g[b].push_back({a,w});
    }
    vector<long long> dist(n + 1, INF);
    vector<int> orig(n + 1, -1);
    dist[1] = 0;
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> p;
    p.push({0, 1});
    while (!p.empty()){
        long long d = p.top().first;
        int u = p.top().second;
        p.pop();
        if (d > dist[u]) continue;
        for (pair<int,int> edge : g[u]){
        int v = edge.first;
        int w = edge.second;
        if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                orig[v] = u;
                p.push({dist[v], v});
            }

        }
    }
    if (dist[n] == INF) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> path;
    for (int v = n; v != -1; v = orig[v]) path.push_back(v);
    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++) cout << path[i] << " ";
    cout << endl;
    return 0;
}
