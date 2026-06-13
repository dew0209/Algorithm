//https://leetcode.cn/problems/weighted-word-mapping/description/?envType=daily-question&envId=2026-06-13

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        string res = "";
        for(int i = 0;i < n;i++){
            string str = words[i];
            int cnt = 0;
            for(auto& st : str){
                cnt = (cnt + weights[st - 'a']);
            }

            //cout << cnt << endl;
            res += (char)('z' - (cnt % 26));
        }
        return res;
    }
};