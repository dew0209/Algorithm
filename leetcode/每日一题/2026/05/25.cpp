//https://leetcode.cn/problems/jump-game-vii/description/?envType=daily-question&envId=2026-05-25

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> f(n,0),pre(n,0);
        for(int i = 0;i < minJump;i++){
            pre[i] = 1;
        }
        f[0] = 1;
        for(int i = minJump;i < n;i++){
            int l = i - maxJump,r = i - minJump;
            if(s[i] == '0'){
                int total = pre[r] - (l <= 0 ? 0 : pre[l - 1]);
                f[i] = (total != 0);
            }
            pre[i] = f[i] + pre[i - 1];
        }
        return f[n - 1];
    }
};