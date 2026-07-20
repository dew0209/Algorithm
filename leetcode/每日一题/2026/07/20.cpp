//https://leetcode.cn/problems/shift-2d-grid/?envType=daily-question&envId=2026-07-20

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> cnt(n * m,0);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                cnt[i * m + j] = grid[i][j];
            }
        }
        int st = 0;
        int ed = n * m - 1;
        for(int i = 0;i < k;i++){
            st = ed;
            ed = (ed + n * m - 1) % (n * m);
        }

        vector<vector<int>> res(n,vector<int>(m,0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                res[i][j] = cnt[st];
                st = (st + 1) % (n * m);
            }
        }
        return res;
    }
};