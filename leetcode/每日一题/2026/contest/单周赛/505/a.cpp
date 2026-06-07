class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int res = 0;
        for(int i = n - k;i <= n + k;i++){
            if(i > 0 && (n & i) == 0){
                res += i;
            }
        }
        return res;
    }
};