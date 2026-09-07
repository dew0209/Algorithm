//https://leetcode.cn/problems/distinct-subsequences/description/?envType=daily-question&envId=2026-09-06


class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n < m){
            return 0;
        }
        vector<vector<unsigned long long>> f(n + 1,vector<unsigned long long>(m + 1,0));
        for(int i = 0;i <= n;i++){
            f[i][m] = 1;
        }
        for(int i = n - 1;i >= 0;i--){
            for(int j = m - 1;j >= 0;j--){
                bool fl = s[i] == t[j];
                if(fl){
                    f[i][j] = f[i + 1][j] + f[i + 1][j + 1];
                }else {
                    f[i][j] = f[i + 1][j];
                }
            }
        }
        return f[0][0];
    }
};