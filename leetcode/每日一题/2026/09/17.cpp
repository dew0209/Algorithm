//https://leetcode.cn/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/?envType=daily-question&envId=2026-09-17


class Solution {
    public int minSumOfLengths(int[] arr, int target) {
        int n = arr.length;
        int[] dp = new int[n];
        // 注意不能设置为最大值，因为相加会溢出
        Arrays.fill(dp, Integer.MAX_VALUE / 2);

        int ans = Integer.MAX_VALUE;
        for(int i = 0, j = 0, sum = 0; j < n; j++){
            sum += arr[j];
            while(i <= j && sum > target){
                sum -= arr[i++];
            }
            // 找到满足条件的一个区间
            if(sum == target){
                dp[j] = j - i + 1;
                if(i != 0){
                    ans = Math.min(ans, dp[i-1] + j - i + 1);
                }
            }
            if(j != 0)
                dp[j] = Math.min(dp[j], dp[j-1]);
        }

        return ans > arr.length ? -1 : ans;
    }
}