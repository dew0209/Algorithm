//https://leetcode.cn/problems/smallest-divisible-digit-product-i/?envType=daily-question&envId=2026-08-06

class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i = n;i <= 100;i++){
            int x = 1;
            int u = i;
            while(u){
                x *= u % 10;
                u /= 10;
            }
            if((x % t) == 0){
                return i;
            }
        }
        return -1;
    }
};