//https://leetcode.cn/problems/stone-game-iv/description/?envType=daily-question&envId=2026-08-10

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> f(n + 1);
        for(int i = 1;i <= n;i++){
            for(int k = 1;k * k <= i;k++){
                if(!f[i - k * k]){
                    f[i] = true;
                    break;
                }
            }
        }
        return f[n];
    }
};