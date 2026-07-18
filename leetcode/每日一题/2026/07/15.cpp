//https://leetcode.cn/problems/gcd-of-odd-and-even-sums/?envType=daily-question&envId=2026-07-15

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int m = n;
        int a = 0;
        int b = 0;
        int st = 1;
        while(m--){
            a += st;
            st += 2;
        }
        st = 2;
        while(n--){
            b += st;
            st += 2;
        }
        return gcd(a,b);
    }
};