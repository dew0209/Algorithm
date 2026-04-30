//https://leetcode.cn/problems/maximum-path-score-in-a-grid/?envType=daily-question&envId=2026-04-30


int f[205][205][1005];
class Solution {
public:
    
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i <= n;i++){
            for(int j = 0;j <= m;j++){
                for(int t = 0;t <= k;t++){
                    f[i][j][t] = INT_MIN;
                }
            }
        }
        f[1][1][0] = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(i == 1 && j == 1)continue;
                int u = grid[i-1][j-1];  // 当前格子的值
                int cost = (u == 0) ? 0 : 1;  // 花费
                for(int t = cost;t <= k;t++){
                    int new_k = t - cost;
                    f[i][j][t] = max(f[i - 1][j][new_k],f[i][j - 1][new_k]) + u;
                    //cout << "i : " << i << " j : " << j << " t : " << t << " ---- > " << f[i][j][t] << endl; 
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 0;i <= k;i++){
            ans = max(f[n][m][i],ans);
        }
        return ans < 0 ? -1 : ans;
    }
};