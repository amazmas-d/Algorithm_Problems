#include <bits/stdc++.h>

using namespace std;

bool isBicolorable(int n, const vector<vector<int>>& adj) {
    vector<int> color(n, -1);
    queue<int> q;
    q.push(0);
    color[0] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int currentColor = color[u];
        int neighborColor = 1 - currentColor;
        for (int v : adj[u]) {
            if (color[v] == -1) {
                color[v] = neighborColor;
                q.push(v);
            } else if (color[v] == currentColor) {
                return false;
            }

        }
    }
    return true;
}

int main() {
    int n, e;
    while (cin >> n && n != 0) {
        cin >> e;
        vector<vector<int>> adj(n);

        for (int i = 0; i < e; ++i) {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if (isBicolorable(n, adj)) {
            cout << "BICOLORABLE." << endl;
        } else {
            cout << "NOT BICOLORABLE." << endl;
        }
    }

    return 0;
}
