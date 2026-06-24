//https://leetcode.cn/problems/maximum-ice-cream-bars/description/?envType=daily-question&envId=2026-06-21

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        vector<int> f(100010,0);
        for(auto& x : costs){
            f[x]++;
        }
        int res = 0;
        for(int i = 1;i < 100010;i++){
            int cnt = f[i];
            if(i <= coins){
                int tol = min(coins / i,cnt);
                coins -= i *tol;
                res += tol;
                f[i] -= tol;
            }else {
                break;
            }
        }
        return res;
    }
};