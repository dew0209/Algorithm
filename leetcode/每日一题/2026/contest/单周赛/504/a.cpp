class Solution {
public:
    int digitFrequencyScore(int n) {
        map<int,int> cnt;
        while(n){
            cnt[n % 10]++;
            n /= 10;
        }
        int res = 0;
        for(auto [x,y] : cnt){
            res += x * y;
        }
        return res;
    }
};