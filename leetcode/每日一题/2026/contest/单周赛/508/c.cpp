const long long INF = 1e18;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<long long>> f(n + 1,vector<long long>(4,0));
        for (int i = 0; i <= n; i++) for (int j = 0; j < 4; j++) f[i][j] = -INF;
        f[0][0] = 0;
        for(int i = 1;i <= n;i++){
            f[i][0] = max(f[i - 1][0],0LL) + nums[i - 1];
            f[i][1] = max({f[i - 1][0],f[i - 1][1],0LL}) + 1LL * nums[i - 1] * k;
            f[i][2] = max({f[i - 1][0],f[i - 1][2],0LL}) + 1LL * nums[i - 1] / k;
            f[i][3] = max({f[i - 1][1],f[i - 1][2],f[i - 1][3],0LL}) + nums[i - 1];
        }
        long long ans = -INF;
        for(int i = 1;i <= n;i++){
            for(int j = 0;j < 4;j++){
                ans = max(ans,f[i][j]);
            }
        }
        return ans;
    }
};