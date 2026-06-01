class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> cnt(n + 1,0);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(i != j){
                    if((items[j][0] % items[i][0]) == 0){
                        cnt[i]++;
                    }
                }
            }
        }
        
        vector<int> f(1510,0);

        for(int i = 1;i <= n;i++){
            int v = items[i - 1][1];
            for(int j = budget;j >= v;j--){
                f[j] = max(f[j],f[j - v] + 1 + cnt[i - 1]);
            }
        }
        for(int i = 1;i <= n;i++){
            int v = items[i - 1][1];
            for(int j = v;j <= budget;j++){
                f[j] = max(f[j],f[j - v] + 1);
            }
        }
        
        
        return f[budget];
    }
};