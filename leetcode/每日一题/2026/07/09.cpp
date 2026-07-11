//https://leetcode.cn/problems/path-existence-queries-in-a-graph-i/description/?envType=daily-question&envId=2026-07-09

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> r;
        for(int i = 1;i < n;i++){
            if(nums[i] - nums[i - 1] > maxDiff){
                r.push_back(i - 1);
            }
        }
        int m = queries.size();
        vector<bool> res(m);
        for(int i = 0;i < m;i++){
            int x = queries[i][0];
            int y = queries[i][1];
            res[i] = ranges::lower_bound(r,x) == ranges::lower_bound(r,y);
        }
        return res;
    }
};