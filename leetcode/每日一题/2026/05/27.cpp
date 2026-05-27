//https://leetcode.cn/problems/count-the-number-of-special-characters-ii/description/?envType=daily-question&envId=2026-05-27

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> a(27,-1);
        vector<int> b(27,-1);
        for(int i = 0;i < word.size();i++){
            char c = word[i];
            if(c >= 'a' && c <= 'z'){
                a[c - 'a'] = max(a[c - 'a'],i);
            }else if(b[c - 'A'] == -1){
                b[c - 'A'] = i;
            }
        }
        int res = 0;
        for(int i = 0;i < 27;i++){
            if(a[i] != -1 && b[i] != -1 && a[i] < b[i]){
                res++;
            }
        }
        return res;
    }
};