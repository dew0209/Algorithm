//https://leetcode.cn/problems/number-of-strings-that-appear-as-substrings-in-word/description/?envType=daily-question&envId=2026-06-29

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int res = 0;
        for(auto& pattern : patterns){
            if(word.contains(pattern)){
                res++;
            }
        }
        return res;
    }
};