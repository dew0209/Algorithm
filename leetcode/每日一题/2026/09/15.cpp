//https://leetcode.cn/problems/maximum-number-of-non-overlapping-palindrome-substrings/description/?envType=daily-question&envId=2026-09-15


class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> st(n + 1,vector<bool>(n + 1,false));
        for(int len = 1;len <= n;len++){
            for(int l = 0;l + len - 1 < n;l++){
                int r = l + len - 1;
                st[l][r] = s[l] == s[r] && (len <= 2 || st[l + 1][r - 1]);
            }
        }
        vector<int> f(n + 1);
        for(int i = 1;i <= n;i++){
            f[i] = f[i - 1];
            for(int j = 0;j + k - 1 <= i - 1;j++){
                if(st[j][i - 1]){
                    f[i] = max(f[i],f[j] + 1);
                }
            }
        }
        return f[n];
    }
};