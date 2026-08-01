//https://leetcode.cn/problems/predict-the-winner/?envType=daily-question&envId=2026-08-01

class Solution {
    public boolean predictTheWinner(int[] nums) {
        int n = nums.length;
        int dp[][] = new int[n][n];
        for (int i = n-1; i >= 0; i--) {
            dp[i][i] = nums[i];
            for (int j = i+1; j <= n-1; j++) {
                dp[i][j] = Math.max(nums[i]-dp[i+1][j],nums[j]-dp[i][j-1]);
            }
        }
        return dp[0][n-1]>=0;
    }
}