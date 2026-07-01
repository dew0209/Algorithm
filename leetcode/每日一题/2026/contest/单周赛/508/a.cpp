class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long res = 0;
        for(int i = n - 1;i >= 0 && k;i--,k--){
            if(mul <= 1){
                mul = 1;
            }
            res = res + nums[i] * 1LL * mul;
            //cout << res << endl;
            mul--;
        }
        return res;
    }
};