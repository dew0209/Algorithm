//https://leetcode.cn/problems/construct-uniform-parity-array-ii/?envType=daily-question&envId=2026-09-03

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(),nums1.end());
        int n = nums1.size();
        vector<vector<bool>> f(n + 1,vector<bool>(2,0));
        int a = -1;
        int b = -1;
        f[0][0] = true;
        f[0][1] = true;


        for(int i = 0;i < n;i++){
            int x = nums1[i];

            //到当前为止，能否构造奇数
            f[i + 1][0] = f[i][0] && ((x % 2 == 1) || (a != -1));
            //到当前为止，能否构造偶数
            f[i + 1][1] = f[i][1] && ((x % 2 == 0) || (a != -1));
             //奇数
            if(x % 2 == 1){
                a = x;
            }
        }
        return f[n][0] || f[n][1];
    }
};