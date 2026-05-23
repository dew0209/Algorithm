//https://leetcode.cn/problems/check-if-array-is-sorted-and-rotated/description/?envType=daily-question&envId=2026-05-23

class Solution {
public:
    bool check(vector<int>& nums) {
        
        bool sorted = true;
        int n = nums.size();
        for(int i = 1;i < n;i++){
            if(nums[i] < nums[i - 1]){
                if(!sorted){
                    return false;
                }
                sorted = false;
            }
        }
        return sorted || nums[0] >= nums[n - 1];
    }
};