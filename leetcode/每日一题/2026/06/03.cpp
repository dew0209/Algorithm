//https://leetcode.cn/problems/earliest-finish-time-for-land-and-water-rides-ii/description/?envType=daily-question&envId=2026-06-03

class Solution {
public:
    int solve(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration){
        int min_fis = INT_MAX;
        for(int i = 0;i < landStartTime.size();i++){
            min_fis = min(min_fis,landStartTime[i] + landDuration[i]);
        }
        int res = INT_MAX;
        for(int i = 0;i < waterStartTime.size();i++){
            res = min(res,max(waterStartTime[i],min_fis) + waterDuration[i]);
        }
        return res;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int a = solve(landStartTime,landDuration,waterStartTime,waterDuration);
        int b = solve(waterStartTime,waterDuration,landStartTime,landDuration);
        return min(a,b);
    }
};