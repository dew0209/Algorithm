//https://leetcode.cn/problems/find-the-safest-path-in-a-grid/?envType=daily-question&envId=2026-07-01

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] || grid[n - 1][n - 1]) {
            return 0;
        }
        
        vector<vector<int>> dis(n, vector<int>(n, -1));
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    q.emplace(i, j);
                    dis[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop();
            for (int j = 0; j < 4; j++) {
                int nx = cx + dirs[j][0];
                int ny = cy + dirs[j][1];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n || dis[nx][ny] != -1) {
                    continue;
                }
                dis[nx][ny] = dis[cx][cy] + 1;
                q.emplace(nx, ny);
            }
        }

        auto check = [&](int limit) -> bool {
            vector<vector<bool>> visit(n, vector<bool>(n, false));
            queue<pair<int, int>> q;
            q.emplace(0, 0);
            visit[0][0] = true;

            while (!q.empty()) {
                auto [cx, cy] = q.front();
                q.pop();
                if (cx == n - 1 && cy == n - 1) {
                    return true;
                }
                for (int i = 0; i < 4; i++) {
                    int nx = cx + dirs[i][0];
                    int ny = cy + dirs[i][1];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n || 
                        visit[nx][ny] || dis[nx][ny] < limit) {
                        continue;
                    }
                    q.emplace(nx, ny);
                    visit[nx][ny] = true;
                }
            }

            return false;
        };


        int lo = 0, hi = min(dis[0][0], dis[n - 1][n - 1]);
        int res = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (check(mid)) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return res;

    }
};
