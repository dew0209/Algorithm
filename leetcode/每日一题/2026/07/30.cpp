//https://leetcode.cn/problems/minimum-number-of-pushes-to-type-word-i/?envType=daily-question&envId=2026-07-30

class Solution {
public:
    int minimumPushes(string word) {
        int step = 1;
        int res = 0;
        int n = word.size();
        while(n > 0){
            res += min(n,8) * step;
            step++;
            n -= 8;
        }
        return res;
    }
};