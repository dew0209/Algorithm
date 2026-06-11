//https://leetcode.cn/problems/number-of-ways-to-assign-edge-weights-i/description/?envType=daily-question&envId=2026-06-11

class Solution {
public:
    int dfs(vector<vector<int>>& edges,int u,int fa){
        int res = 0;
        for(auto& edge : edges[u]){
            if(edge != fa){
                res = max(res,dfs(edges,edge,u) + 1);
            }
        }
        return res;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        //奇数的个数是奇数个
        int m = edges.size();
        int n = m + 1;
        vector<vector<int>> mp(n + 1);
        for(auto& ed : edges){
            int v = ed[0];
            int w = ed[1];
            mp[v].push_back(w);
            mp[w].push_back(v);
        }
        int deep = dfs(mp,1,-1);
        
        long long res = 1;

        for(int i = 0;i < deep - 1;i++){
            res = res * 2 % 1000000007;
        }

        return res;
    }
};