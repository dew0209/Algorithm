//https://leetcode.cn/problems/check-divisibility-by-digit-sum-and-product/?envType=daily-question&envId=2026-08-22

class Solution {
public:
    bool checkDivisibility(int n) {
        int a = 0;
        int b = 1;
        int r = n;
        while(r){
            a += r % 10;
            b *= r % 10;
            r /= 10;
        }
        cout << a << " - " << b << endl;
        return (n % (a + b) == 0);
    }
};