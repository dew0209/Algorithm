//https://leetcode.cn/problems/reverse-degree-of-a-string/?envType=daily-question&envId=2026-09-20

class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int res = 0;
        for(int i = 1;i <= n;i++){
            int x = s[i - 1] - 'a';
            //cout << 26 - x  << " --- " << x << endl;
            res = res + i * (26 - x);
            //cout << res << endl;
        }
        return res;
    }
};