class Solution {
public:
    bool checkGoodInteger(int n) {
        int a = 0;
        int b = 0;
        while(n){
            int x = n % 10;
            a += x;
            b += x * x;

            n /= 10;
        }
        return b - a >= 50;
    }
};