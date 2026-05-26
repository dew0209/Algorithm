//https://leetcode.cn/problems/count-the-number-of-special-characters-i/description/?envType=daily-question&envId=2026-05-26

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> a(27,0);
        vector<int> b(27,0);
        for(int i = 0;i < word.size();i++){
            char c = word[i];
            if(c >= 'a' && c <= 'z'){
                a[c - 'a']++;
            }else {
                b[c - 'A']++;
            }
        }
        int res = 0;
        for(int i = 0;i < 27;i++){
            if(a[i] && b[i]){
                res++;
            }
        }
        return res;
    }
};