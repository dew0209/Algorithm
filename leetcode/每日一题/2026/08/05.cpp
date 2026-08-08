//https://leetcode.cn/problems/remove-methods-from-project/description/?envType=daily-question&envId=2026-08-05

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> g(n);
        for(auto& e : invocations){
            g[e[0]].push_back(e[1]);
        }
        vector<int> st(n);
        auto dfs = [&](auto&& dfs,int x)->void {
            st[x] = 1;
            for(int y : g[x]){
                if(!st[y]){
                    dfs(dfs,y);
                }
            }
        };
        dfs(dfs,k);
        for(auto& e : invocations){
            if(!st[e[0]] && st[e[1]]){
                vector<int> ans(n);
                iota(ans.begin(),ans.end(),0);
                return ans;
            }
        }
        vector<int> ans;
        for(int i = 0;i < n;i++){
            if(!st[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};