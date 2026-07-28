//https://leetcode.cn/problems/maximum-product-of-two-elements-in-an-array/?envType=daily-question&envId=2026-07-27

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return (nums.back() - 1) * (nums[nums.size() - 2] - 1);
    }
};
