//https://leetcode.cn/problems/find-the-largest-almost-missing-integer/?envType=daily-question&envId=2026-08-18

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int a = nums[0];
        int n = nums.size();
        int b = nums[n - 1];
        int mx = max(a,b);
        map<int,int> cnt;
        cnt[nums[0]]++;
        cnt[nums[n - 1]]++;
        for(int i = 1;i < n - 1;i++){
            if(nums[i] == a){
                a = -1;
            }
            if(nums[i] == b){
                b = -1;
            }
            cnt[nums[i]]++;
            mx = max(mx,nums[i]);
        }
        if(n == k){
            return mx;
        }
        if(k == 1){
            int res = -1;
            for(auto [x,y] : cnt){
                cout << x << " --- " << y << endl;
                if(y == 1){
                    res = max(res,x);
                    cout << res << " 000 ";
                }
            }
            //cout << res << endl;
            return res;
        }
        if(a == b){
            a = b = -1;
        }
        return max(a,b);
    }
};