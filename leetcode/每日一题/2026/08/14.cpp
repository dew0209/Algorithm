//https://leetcode.cn/problems/maximum-length-substring-with-two-occurrences/?envType=daily-question&envId=2026-08-14

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int res = 0;
        for (int left = 0; left < n; ++left) {
            array<int, 26> count{};
            for (int right = left; right < n; ++right) {
                const int index = s[right] - 'a';
                ++count[index];
                if (count[index] > 2) {
                    break;
                }
                res = max(res, right - left + 1);
            }
        }
        return res;
    }
};