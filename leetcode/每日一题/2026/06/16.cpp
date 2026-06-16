//https://leetcode.cn/problems/process-string-with-special-operations-i/description/?envType=daily-question&envId=2026-06-16

class Solution {
public:
    string processStr(string s) {
        string res = "";
        int n = s.size();
        for(int i = 0;i < n;i++){
            if(s[i] == '*'){
                if(res.size()){
                    res = res.substr(0,res.size() - 1);
                }
            }else if(s[i] == '#'){
                res = res + res;
            }else if(s[i] == '%'){
                reverse(res.begin(),res.end());
            }else {
                res += s[i];
            }
            //cout << res << endl;
        }
        return res;
    }
};