//https://leetcode.cn/problems/minimum-number-of-pushes-to-type-word-ii/?envType=daily-question&envId=2026-07-31

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        map<int,int> cnt;
        for(auto c : word){
            cnt[c - 'a']++;
        }
        int res = 0;
        int sum = 1;
        int step = 1;
        vector<int> count;
        for(auto [x,y] : cnt){
            count.push_back(y);
        }
        sort(count.begin(),count.end());
        reverse(count.begin(),count.end());
        for(auto y : count){
            res += y * step;
            //cout << y << " --- " << step << " --- " << res << endl;
            sum++;
            if(sum >= 9){
                sum = 1;
                step++;
            }
        }
        return res;
    }
};