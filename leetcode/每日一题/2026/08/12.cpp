//https://leetcode.cn/problems/length-of-longest-subarray-with-at-most-k-frequency/description/?envType=daily-question&envId=2026-08-12

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> cnt;
        int l = 0;
        int res = 0;
        for(int r = 0;r < n;r++){
            cnt[nums[r]]++;
            while(l < r && cnt[nums[r]] > k){
                cnt[nums[l]]--;
                l++;
            }
            res = max(res,r - l + 1);
        }
        return res;
    }
};