//https://leetcode.cn/problems/unique-3-digit-even-numbers/?envType=daily-question&envId=2026-09-11

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> cnt;
        int n = digits.size();
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(i == j)continue;
                for(int k = 0;k < n;k++){
                    if(i == k || k == j)continue;
                    if(digits[i] != 0 && digits[k] % 2 == 0){
                        int r = digits[i] * 100 + digits[j] * 10 + digits[k];
                        //cout << r << endl;
                        cnt.insert(r);
                    }
                }
            }
        }
        return cnt.size();
    }
};