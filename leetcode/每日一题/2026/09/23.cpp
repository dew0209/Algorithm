//https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/description/?envType=daily-question&envId=2026-09-23

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int ans = n + 1;
        int sum = 0;
        for(int i = 0;i < n;i++){
            sum += nums[i];
        }
        if(sum < x)return -1;

        int lsum = 0,rsum = sum;
        int right = 0;
        
        
        for(int left = -1;left < n;left++){
            if(left != -1){
                lsum += nums[left];
            }
            while(right < n && lsum + rsum > x){
                rsum -= nums[right];
                right++;
            }
            if(rsum + lsum == x){
                ans = min(ans,left + 1 + n - right);
            }
        }
        return ans == n + 1 ? -1 : ans;
    }
};