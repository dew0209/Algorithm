//https://leetcode.cn/problems/maximize-active-section-with-trade-i/description/?envType=daily-question&envId=2026-07-21

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int cnt1 = count(s.begin(),s.end(),'1');
        vector<int> zero;
        int i = 0;
        while(i < n){
            int st = i;
            while(i < n && s[i] == s[st]){
                i++;
            }
            if(s[st] == '0'){
                zero.push_back(i - st);
            }
        }
        int m = zero.size();
        if(m < 2){
            return cnt1;
        }
        int res = 0;
        for(int i = 0;i < m - 1;i++){
            res = max(res,cnt1 + zero[i] + zero[i + 1]);
        }
        return res;
    }
};