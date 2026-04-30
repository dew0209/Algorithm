//https://leetcode.cn/problems/maximum-score-from-grid-operations/description/?envType=daily-question&envId=2026-04-29

class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        // 每列的前缀和（从上到下）
        vector<vector<long long>> col_sum(n, vector<long long>(n + 1));
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                col_sum[j][i + 1] = col_sum[j][i] + grid[i][j];
            }
        }

        vector<vector<array<long long, 2>>> f(n, vector<array<long long, 2>>(n + 1));
        for (int j = 0; j < n - 1; j++) {
            // pre 表示第 j+1 列的黑格个数
            for (int pre = 0; pre <= n; pre++) {
                // dec=1 意味着第 j+1 列的黑格个数 (pre) < 第 j+2 列的黑格个数
                for (int dec = 0; dec < 2; dec++) {
                    auto& res = f[j + 1][pre][dec];
                    // 枚举第 j 列有 cur 个黑格
                    for (int cur = 0; cur <= n; cur++) {
                        if (cur == pre) { // 情况一：相等
                            // 没有可以计入总分的格子
                            res = max(res, f[j][cur][0]);
                        } else if (cur < pre) { // 情况二：右边黑格多
                            // 第 j 列的第 [cur, pre) 行的格子可以计入总分
                            res = max(res, f[j][cur][1] + col_sum[j][pre] - col_sum[j][cur]);
                        } else if (dec == 0) { // 情况三：cur > pre >= 第 j+2 列的黑格个数
                            // 第 j+1 列的第 [pre, cur) 行的格子可以计入总分
                            res = max(res, f[j][cur][0] + col_sum[j + 1][cur] - col_sum[j + 1][pre]);
                        } else if (pre == 0) { // 情况四（凹形）：cur > pre < 第 j+2 列的黑格个数
                            // 此时第 j+2 列全黑最优（递归过程中一定可以枚举到这种情况）
                            // 第 j+1 列全白是最优的，所以只需考虑 pre=0 的情况
                            // 由于第 j+1 列在 dfs(j+1) 的情况二中已经统计过，这里不重复统计
                            res = max(res, f[j][cur][0]);
                        }
                    }
                }
            }
        }

        // 枚举第 n-1 列有 i 个黑格
        long long ans = 0;
        for (auto& row : f[n - 1]) {
            ans = max(ans, row[0]);
        }
        return ans;
    }

};