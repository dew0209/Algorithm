//https://leetcode.cn/problems/left-and-right-sum-differences/description/?envType=daily-question&envId=2026-06-06

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> sum(n + 1,0);
        for(int i = 0;i < n;i++){
            sum[i + 1] += sum[i] + nums[i];
        }
        vector<int> ans(n,0);
        for(int i = 0;i < n;i++){
            ans[i] = abs(sum[i] - sum[n] + sum[i + 1]);
        }
        return ans;
    }
};