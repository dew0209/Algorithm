class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int n = units.size();
        int m = units[0].size();
        for(auto& unit : units){
            sort(unit.begin(),unit.end());
        }
        long long sum = 0;
        if(m == 1){
            for(auto& unit : units){
                sum += unit[0];
            }
            return sum;
        }
        int mn = units[0][0];
        for(auto& unit : units){
            mn = min(mn,unit[0]);
            sum += unit[1];
        }
        long long ans = 0;
        for(auto& unit : units){
            ans = max(ans,sum - unit[1] + mn);
        }
        return ans;
    }
};