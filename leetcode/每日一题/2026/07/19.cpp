//https://leetcode.cn/problems/smallest-subsequence-of-distinct-characters/?envType=daily-question&envId=2026-07-19

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> st(26),num(26);
        for(auto ch : s){
            num[ch - 'a']++;
        }
        string stk;
        for(auto ch : s){
            if(!st[ch - 'a']){
                while(!stk.empty() && stk.back() > ch){
                    if(num[stk.back() - 'a'] > 0){
                        st[stk.back() - 'a'] = 0;
                        stk.pop_back();
                    }else{
                        break;
                    }
                }
                st[ch - 'a'] = 1;
                stk.push_back(ch);
            }
            num[ch - 'a'] -= 1;
        }
        return stk;
    }
};