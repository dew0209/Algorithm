//https://leetcode.cn/problems/stone-game-iii/description/?envType=daily-question&envId=2026-08-03

class Solution {
public:
    string stoneGameIII(vector<int>& stone) {
        int n = stone.size();
        vector<int> sum(n);
        sum[n - 1] = stone[n - 1];
        for(int i = n - 2;i >= 0;i--){
            sum[i] = sum[i + 1] + stone[i];
        }
        vector<int> f(n + 1);
        for(int i = n - 1;i >= 0;i--){
            int v = f[i + 1];
            for(int j = i + 2;j <= i + 3 && j <= n;j++){
                v = min(f[j],v);
            }
            f[i] = sum[i] - v;
        }
        if(f[0] + f[0] == sum[0])return "Tie";
        return f[0] + f[0] > sum[0] ? "Alice" : "Bob";
    }
};