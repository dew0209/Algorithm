//https://leetcode.cn/problems/distinct-subsequences-ii/description/?envType=daily-question&envId=2026-09-07

const int MOD = 1e9 + 7;
class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> f(n + 1,1);
        vector<int> last(26,-1);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < 26;j++){
                if(last[j] != -1){
                    f[i] = (f[i] + f[last[j]]) % MOD;
                }
            }

            last[s[i] - 'a'] = i;
        }
        long long res = 0;
        for(int i = 0;i < 26;i++){
            if(last[i] != -1){
                res = (long long)(res + (long long)f[last[i]]) % MOD;
            }
        }
        return res;
    }
};