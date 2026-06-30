//https://leetcode.cn/problems/number-of-substrings-containing-all-three-characters/description/?envType=daily-question&envId=2026-06-30

class Solution {
public:
    int numberOfSubstrings(string s) {
        int len = s.size();
        int ans = 0;
        vector<vector<int>> pre(3,vector<int>(len + 1));
        pre[0][0] = pre[0][1] = pre[0][2] = 0;
        for(int i = 0;i < len;i++){
            for(int j = 0;j < 3;j++){
                pre[j][i + 1] = pre[j][i];
            }
            pre[s[i] - 'a'][i + 1]++;
        }
        for(int i = 0;i < len;i++){
            int l = i + 1,r = len,pos = -1;
            while(l <= r){
                int mid = l + r >> 1;
                if(pre[0][mid] - pre[0][i] > 0 && 
                    pre[1][mid] - pre[1][i] > 0 && 
                    pre[2][mid] - pre[2][i] > 0 ){
                    r = mid - 1;
                    pos = mid;
                }else { 
                    l = mid + 1;
                }
            }
            if(pos != -1){
                ans += len - pos + 1;
            }
        }
        return ans;
    }
};