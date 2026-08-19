//https://leetcode.cn/problems/longest-subsequence-with-non-zero-bitwise-xor/?envType=daily-question&envId=2026-08-15

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool isZreo = true;
        int n = nums.size();
        int res = 0;
        for(int i = 0;i < n;i++){
            if(nums[i] != 0){
                isZreo = false;
            }
            res ^= nums[i];
        }
        if(isZreo){
            return 0;
        }
        return n - (res == 0);
    }
};