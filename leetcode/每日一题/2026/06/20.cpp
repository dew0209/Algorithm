//https://leetcode.cn/problems/maximum-building-height/?envType=daily-question&envId=2026-06-20

class Solution {
public:
    int maxBuilding(int m, vector<vector<int>>& restrictions) {
        int n = restrictions.size();
        if(n == 0)return m - 1;
        ranges::sort(restrictions,{},[](auto& a){return a[0];});
        vector<int> h(n);
        h[0] = min(restrictions[0][0] - 1,restrictions[0][1]);
        for(int i = 1;i < n;i++){
            h[i] = min(h[i - 1] + restrictions[i][0] - restrictions[i - 1][0],restrictions[i][1]);
        }
        for(int i = n - 2;i >= 0;i--){
            h[i] = min(h[i],h[i + 1] + restrictions[i + 1][0] - restrictions[i][0]);
        }
        int ans = max((restrictions[0][0] - 1 + h[0]) / 2,h[n - 1] + m - restrictions[n - 1][0]);
        for(int i = 0;i < n - 1;i++){
            ans = max(ans,(restrictions[i + 1][0] - restrictions[i][0] + h[i] + h[i + 1]) / 2);
        }
        return ans;
    }
};