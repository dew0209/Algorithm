//https://leetcode.cn/problems/stone-game/?envType=daily-question&envId=2026-08-02

class Solution {
     public static boolean stoneGame(int[] piles) {
        int m = piles.length;
        boolean dp[][] = new boolean[m][m];
        for (int i = 0; i < m; i++) {//len = 1的情况
            dp[i][i] = true;
        }
        for (int len = 1; len < m; len++) {
            for (int l = 0; l < m - len; l++) {
                int r = l+len;//
                for (int k = l; k < r; k++) {
                    if (dp[l+1][r] || dp[l][r-1]){
                        dp[l][r] = true;
                    }
                }
            }
        }
        
        return dp[0][m-1];
    }
}