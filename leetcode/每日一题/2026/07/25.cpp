//https://leetcode.cn/problems/maximum-product-of-two-digits/?envType=daily-question&envId=2026-07-25

class Solution {
public:
    int maxProduct(int n) {
        int first = 0, second = 0;
        while (n > 0) {
            int x = n % 10;
            if (x > first) {
                second = first;
                first = x;
            } else if (x > second) {
                second = x;
            }
            n /= 10;
        }
        return first * second;
    }
};
