//https://leetcode.cn/problems/minimum-element-after-replacement-with-digit-sum/description/?envType=daily-question&envId=2026-05-29


class Solution {
public:
    int get_d(int u){
        int res = 0;
        while(u){
            res += u % 10;
            u /= 10;
        }
        return res;
    }
    int minElement(vector<int>& nums) {
        int res = 200000;
        for(int i = 0;i < nums.size();i++){
            res = min(res,get_d(nums[i]));
        }
        return res;
    }
};