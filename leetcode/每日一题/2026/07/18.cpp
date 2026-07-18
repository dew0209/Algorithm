//https://leetcode.cn/problems/find-greatest-common-divisor-of-array/?envType=daily-question&envId=2026-07-18


class Solution {
public:
    int findGCD(vector<int>& nums) {
        int v1 = 1;
        int v2 = 1000;
        for(auto& num : nums){
            v1 = max(v1,num);
            v2 = min(v2,num);
        }
        return gcd(v1,v2);
    }
};