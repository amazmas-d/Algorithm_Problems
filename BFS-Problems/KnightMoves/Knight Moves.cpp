#include <bits/stdc++.h>
using namespace std;

const int kr[] = {2, 2, -2, -2, 1, 1, -1, -1};
const int kc[] = {1, -1, 1, -1, 2, -2, 2, -2};

int bfs_knight(int startR, int startC, int endR, int endC)
{
    const int n = 8;
    int dis[n][n];
    int color[n][n];
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dis[i][j] = INT_MAX;
            color[i][j] = -1;    // -1 -> white (unvisited)
        }
    }
    dis[startR][startC] = 0;
    color[startR][startC] = 1; // 1 -> gray (in queue)
    q.push({startR, startC});

    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();

        int r = u.first;
        int c = u.second;
        if (r == endR && c == endC) {
            return dis[r][c];
        }
        for (int i = 0; i < 8; i++) {
            int new_r = r + kr[i];
            int new_c = c + kc[i];

            // Check if the move is on the board and the square is unvisited
            if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < n && color[new_r][new_c] == -1) {
                color[new_r][new_c] = 1; // Mark as gray (in queue)
                dis[new_r][new_c] = dis[r][c] + 1;
                q.push({new_r, new_c});
            }
        }
        color[r][c] = 2; // 2 -> black (processed)
    }

    // This should not happen if start and end are the same
    if (startR == endR && startC == endC) return 0;

    return -1;
}

int main()
{
    string s1, s2;

    // Read test cases until there is no more input
    while (cin >> s1 >> s2) {
        // Convert algebraic notation  to 0-indexed coordinates
        int startR = s1[1] - '1';
        int startC = s1[0] - 'a';
        int endR = s2[1] - '1';
        int endC = s2[0] - 'a';

        int moves = bfs_knight(startR, startC, endR, endC);

        cout << "To get from " << s1 << " to " << s2 << " takes " << moves << " knight moves." << endl;
    }

    return 0;
}
