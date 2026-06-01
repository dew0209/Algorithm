//https://leetcode.cn/problems/minimum-cost-of-buying-candies-with-discount/description/?envType=daily-question&envId=2026-06-01

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        int res = 0;
        sort(cost.begin(),cost.end());
        for(int i = n - 1;i >= 0;i -= 3){
            int a = cost[i];
            res += a;
            if(i - 1 >= 0){
                res += cost[i - 1];
            }
        }
        return res;
    }
};