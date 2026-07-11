//https://leetcode.cn/problems/concatenate-non-zero-digits-and-multiply-by-sum-ii/?envType=daily-question&envId=2026-07-08


const int MOD = 1e9 + 7;
const int MAX_N = 100001;
long long pow10[MAX_N];

// init 对于所有测试用例只运行一次
int init = []() {
    pow10[0] = 1;
    for (int i = 1; i < MAX_N; ++i) {
        pow10[i] = (pow10[i - 1] * 10) % MOD;
    }
    return 0;
}();


class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<long long> cnt(n + 1,0);
        vector<int> sum(n + 1,0);
        vector<int> tol(n + 1,0);
        long long tol_v = 0;
        for(int i = 1;i <= n;i++){
            int c = s[i - 1] - '0';
            if(c){
                tol_v = (tol_v * 10 + c) % MOD;
            }
            
            cnt[i] = tol_v;
            sum[i] += sum[i - 1] + c;
            tol[i] = tol[i - 1] + (c > 0);
        }
        int m = queries.size();
        vector<int> res(m,0);
        for(int i = 0;i < m;i++){
            int l = queries[i][0];
            int r = queries[i][1] + 1;
            long long calc = (cnt[r] - cnt[l] * pow10[(tol[r] - tol[l])] % MOD + MOD) % MOD;
            long long ans = calc * (sum[r] - sum[l]) % MOD;
            res[i] = ans;
        }
        return res;
    }
};