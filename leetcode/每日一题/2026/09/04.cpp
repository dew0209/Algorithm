//https://leetcode.cn/problems/smallest-stable-index-i/?envType=daily-question&envId=2026-09-04

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> max_v(n + 1,0);
        vector<int> min_v(n + 2,2e9);
        for(int i = 0;i < n;i++){
            max_v[i + 1] = max(max_v[i],nums[i]);
        }
        for(int i = n - 1;i >= 0;i--){
            min_v[i + 1] = min(min_v[i + 2],nums[i]);
        }
        int res = -1;
        for(int i = 0;i < n;i++){
            if(max_v[i + 1] - min_v[i + 1] <= k){
                res = i;
                break;
            }
        }
        return res;
    }
};