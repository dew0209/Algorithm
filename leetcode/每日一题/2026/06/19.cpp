//https://leetcode.cn/problems/find-the-highest-altitude/description/?envType=daily-question&envId=2026-06-19

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0;
        int s = 0;
        for(auto& g : gain){
            s += g;
            res = max(res,s);
        }
        return res;
    }
};