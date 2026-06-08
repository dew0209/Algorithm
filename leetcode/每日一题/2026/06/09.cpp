//https://leetcode.cn/problems/maximum-total-subarray-value-i/description/?envType=daily-question&envId=2026-06-09

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int minv = 2e9;
        int maxv = 0;
        for(int i = 0;i < n;i++){
            minv = min(nums[i],minv);
            maxv = max(nums[i],maxv);
        }
        return (maxv - minv) * 1LL * k;
    }

};  