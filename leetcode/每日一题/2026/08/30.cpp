//https://leetcode.cn/problems/removing-minimum-and-maximum-from-array/?envType=daily-question&envId=2026-08-30

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minidx = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxidx = max_element(nums.begin(), nums.end()) - nums.begin();
        int l = min(minidx, maxidx);   // 最值下标中的较小值
        int r = max(minidx, maxidx);   // 最值下标中的较大值
        return min({r + 1, n - l, l + 1 + n - r});   // 计算三种情况下删除次数的最小值
    }
};
