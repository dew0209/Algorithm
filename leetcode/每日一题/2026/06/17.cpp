//https://leetcode.cn/problems/process-string-with-special-operations-ii/?envType=daily-question&envId=2026-06-17

class Solution {
public:
    char processStr(string s, long long k) {
        /**
            如果字符是 小写 英文字母，则将其添加到 result 中。
            字符 '*' 会 删除 result 中的最后一个字符（如果存在）。
            字符 '#' 会 复制 当前的 result 并追加到其自身后面。
            字符 '%' 会 反转 当前的 result。
        */
        long long len = 0;
        int n = s.size();

        for(int i = 0;i < n;i++){
            if(s[i] == '*'){
                if(len){
                    len--;
                }
            }else if(s[i] == '#'){
                len = len * 2;
            }else if(s[i] == '%'){

            }else {
                len++;
            }
        }
        if(k + 1 > len)return '.';

        for(int i = n - 1;i >= 0;i--){
            if(s[i] == '*'){
                len++;
            }else if(s[i] == '#'){
                if(k + 1 > (len + 1) / 2){
                    k -= len / 2;
                }
                len = (len + 1) / 2;
            }else if(s[i] == '%'){
                k = len - 1 - k;
            }else {
                if(k + 1 == len){
                    return s[i];
                }
                len--;
            }
        }

        return '.';
    }
};