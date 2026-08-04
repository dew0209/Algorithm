//https://leetcode.cn/problems/find-missing-elements/description/?envType=daily-question&envId=2026-08-04

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(110,0);
        bool flag = false;
        int mv = 0;
        for(auto num : nums){
            cnt[num] = 1;
            mv = max(mv,num);
        }
        vector<int> res;
        for(int i = 1;i <= mv;i++){
            if(cnt[i]){
                flag = true;
            }
            if(flag && !cnt[i]){
                res.push_back(i);
            }
        }
        return res;
    }
};