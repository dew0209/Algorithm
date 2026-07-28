//https://leetcode.cn/problems/smallest-palindromic-rearrangement-i/description/?envType=daily-question&envId=2026-07-28

class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> cnt(26,0);
        int n = s.size();
        for(auto c : s){
            cnt[c - 'a']++;
        }
        string res(n, ' ');
        int l = 0,r = n - 1;
        for(int i = 0;i < 26;i++){
            if(cnt[i] && (cnt[i] % 2 == 1)){
                res[n / 2]  = (char)(i + 'a');
                cnt[i]--;
            }
            while(cnt[i] > 0){
                res[l++]  = (char)(i + 'a');
                res[r--]  = (char)(i + 'a');
                cnt[i] -= 2;
            }
        }
        return res;
    }
};
