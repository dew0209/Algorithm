//https://leetcode.cn/problems/smallest-missing-multiple-of-k/?envType=daily-question&envId=2026-08-25

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> cnt;
        for(auto& num : nums){
            cnt.insert(num);
        }
        int res = k;
        int count = 1;
        while(cnt.contains(res)){
            count++;
            res = k * count;
        }
        return res;
    }
};