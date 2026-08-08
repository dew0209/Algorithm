//https://leetcode.cn/problems/find-the-lexicographically-smallest-valid-sequence/description/?envType=daily-question&envId=2026-08-08

class Solution {
public:
    vector<int> validSequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> suf(n + 1);
        //suf[n] = m;
        for(int i = n - 1,j = m - 1;i >= 0;i--){
            if(j >= 0 && s[i] == t[j]){
                j--;
            }
            suf[i] = j + 1;   
        }
        vector<int> ans(m);
        bool change = false;
        int j = 0;
        for(int i = 0;i < n;i++){
            if(s[i] == t[j] || (!change && suf[i + 1] <= j + 1)){
                if(s[i] != t[j]){
                    change = true;
                }
                ans[j++] = i;
                if(j == m){
                    return ans;
                }
            }
        }
        return {};
    }
};