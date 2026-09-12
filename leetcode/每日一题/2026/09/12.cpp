//https://leetcode.cn/problems/maximum-score-of-non-overlapping-intervals/?envType=daily-question&envId=2026-09-12

struct Node{
    int l,r,weight,idx;
    bool operator<(const Node& other) const {
        return r < other.r;
    }
};
class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Node> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({intervals[i][0], intervals[i][1], intervals[i][2], i});
        }
        sort(arr.begin(), arr.end());

        vector<vector<long long>> dp(n + 1,vector<long long>(5));
        vector<vector<vector<int>>> indices(n + 1,vector<vector<int>>(5));
        for(int i = 0;i < n;i++){
            auto [l,r,weight,idx] = arr[i];
            int k = lower_bound(arr.begin(),arr.begin() + i,l,[](const Node& a, int val) {
                return a.r < val;
            }) - arr.begin();
            for(int j = 1;j < 5;j++){
                long long s1 = dp[i][j];
                long long s2 = dp[k][j - 1] + weight;
                if(s1 > s2){
                    dp[i + 1][j] = dp[i][j];
                    indices[i + 1][j] = indices[i][j];
                    continue;
                }

                vector<int> newIndex = indices[k][j - 1];
                newIndex.push_back(idx);
                if(s1 == s2 && indices[i][j] < newIndex){
                    newIndex = indices[i][j];
                }
                sort(newIndex.begin(),newIndex.end());
                dp[i + 1][j] = s2;
                indices[i + 1][j] = newIndex;

            }
        }
        return indices[n][4];
    }
};