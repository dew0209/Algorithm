//https://leetcode.cn/problems/maximum-number-of-balloons/?envType=daily-question&envId=2026-06-22

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> cnt(26,0);
        for(int i = 0;i < text.size();i++){
            cnt[text[i] - 'a']++;
        }
        int res = 10000;

        res = min(cnt[0],res);
        res = min(cnt[1],res);
        res = min(cnt[11] / 2,res);
        res = min(cnt[14] / 2,res);

        return min(cnt[13],res);
    }
};