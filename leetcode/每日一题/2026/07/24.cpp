//https://leetcode.cn/problems/number-of-unique-xor-triplets-ii/?envType=daily-question&envId=2026-07-24

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<int> cnt(3000,0);
        int n = nums.size();
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                cnt[nums[i] ^ nums[j]] = 1;
            }
        }
        vector<int> count(3000,0);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < 3000;j++){
                if(!cnt[j])continue;
                count[nums[i] ^ j] = 1;
            }
        }
        int res = 0;
        for(int i = 0;i < 3000;i++){
            if(count[i]){
                res++;
            }
        }
        return res;
    }
};