//https://leetcode.cn/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/description/?envType=daily-question&envId=2026-07-07

class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int> cnt;
        while(n){
            if(n % 10){
                cnt.push_back(n % 10);
            }
            n /= 10;
        }
        int sum = 0;
        int x = 0;
        for(int i = cnt.size() - 1;i >= 0;i--){
            sum += cnt[i];
            x = x * 10 + cnt[i];
        }
        return sum * 1LL * x;
    }
};