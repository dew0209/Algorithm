//https://leetcode.cn/problems/find-x-value-of-array-i/?envType=daily-question&envId=2026-09-21

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> result(k);
        vector<long long> f(k);
        for(int i = 0;i < n;i++){
            vector<long long> f1(k);
            f1[nums[i] % k] += 1;
            for(int r = 0;r < k;r++){
                f1[1LL * r * nums[i] % k] += f[r];
            }
            f = f1;
            for(int r = 0;r < k;r++){
                result[r] += f[r];
            }
        }
        return result;
    }
};