//https://leetcode.cn/problems/count-commas-in-range/description/?envType=daily-question&envId=2026-09-08

class Solution {
public:
    int countCommas(int n) {
        int cnt = 0;
        for(int i = 1;i <= n;i++){
            if(i >= 1000 && i <= 100000){
                cnt++;
            }
        }
        return cnt;
    }
};