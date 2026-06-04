//https://leetcode.cn/problems/total-waviness-of-numbers-in-range-i/description/?envType=daily-question&envId=2026-06-04

class Solution {
public:
    int get_d(int u){
        string s = to_string(u);
        int res = 0;
        for(int i = 1;i < s.size() - 1;i++){
            int a = s[i - 1] - '0';
            int b = s[i] - '0';
            int c = s[i + 1] - '0';
            if((b > a && b > c) || (b < a && b < c)){
                res++;
            }
        }
        return res;
    }
    int totalWaviness(int num1, int num2) {
        int res = 0;
        for(int i = num1;i <= num2;i++){
            res += get_d(i);
        }
        return res;
    }
};