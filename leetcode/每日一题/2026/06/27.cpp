//https://leetcode.cn/problems/find-the-maximum-number-of-elements-in-subset/description/?envType=daily-question&envId=2026-06-27


class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;
        for(int num : nums){
            cnt[num]++;
        }
        int res = 0;
        if (cnt[1] % 2 == 0) {
            res = cnt[1] - 1;
        } else {
            res = cnt[1];
        }
        cnt.erase(1);
        for(auto& [num,_] : cnt){
            int ans = 0;
            long long x = num;
            for(;cnt.contains(x) && cnt[x] > 1;x = x * x){
                ans += 2;
            }
            if(cnt.contains(x) && cnt[x] > 0){
                ans += 1;
            }else {
                ans -= 1;
            }
            res = max(res,ans);
        }
        return res;
    }
};