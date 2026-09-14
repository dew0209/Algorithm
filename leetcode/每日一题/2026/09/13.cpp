//https://leetcode.cn/problems/image-overlap/?envType=daily-question&envId=2026-09-13

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size(),ans = 0;
        auto get = [&](int ud,int lr)->int{
            int res = 0;
            for(int i=0;i<n;i++)if(0<=(i+ud) && (i+ud)<n){
                for(int j=0;j<n;j++)if(0<=(j+lr) && (j+lr)<n){
                    res += img1[i+ud][j+lr]&img2[i][j];
                }
            }
            return res;
        };
        for(int i=-n;i<=n;i++){
            for(int j=-n;j<=n;j++){
                ans = max(ans,get(i,j));
            }
        }
        return ans;
    }
};