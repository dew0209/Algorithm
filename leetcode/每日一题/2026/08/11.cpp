//https://leetcode.cn/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/description/?envType=daily-question&envId=2026-08-11

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        set<int> st;
        for(int i = 0;i < n;i++){
            st.insert(nums[i]);
        }
        int mx = nums[0];
        int j = 1;
        while(j < n && nums[j] == nums[j - 1] + 1){
            mx += nums[j];
            j++;
        }
        int res = mx;
        while(st.contains(res)){
            res++;
        }
        return res;
    }
};