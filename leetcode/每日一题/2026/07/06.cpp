//https://leetcode.cn/problems/remove-covered-intervals/description/?envType=daily-question&envId=2026-07-06


class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,int>> cnt;
        int n = intervals.size();
        for(int i = 0;i < n;i++){
            cnt.push_back({intervals[i][0],intervals[i][1]});
        }
        sort(cnt.begin(),cnt.end());
        vector<pair<int,int>> res;
        int st = -2e9,ed = -2e9;
        for(int i = 0;i < n;i++){
            auto t = cnt[i];
            bool f1 = t.first > ed;
            bool f2 = t.first < ed && t.second > ed && t.first > st;
            if(f1 || f2){
                if(st != -2e9){
                    res.push_back({st,ed});
                }
                st = t.first;
            }
            ed = max(ed,t.second);
        }

        if(st != -2e9){
            res.push_back({st,ed});
        }
        return res.size();
    }
};