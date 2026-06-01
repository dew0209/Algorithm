class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int minv = 2e9;
        vector<int> cnt(n + 1);
        for(auto& item : items){
            cnt[item[0]]++;
            minv = min(minv,item[1]);
        }
        vector<int> cnt_2(n + 1);
        vector<pair<int,int>> a;
        for(auto& item : items){
            int x = item[0],y = item[1];
            if(y >= minv * 2){
                continue;
            }
            int& cnt_v = cnt_2[x];
            if(cnt_v == 0){
                for(int j = x;j <= n;j += x){
                    cnt_v += cnt[j];
                }
            }
            if(cnt_v > 1){
                a.push_back({y,cnt_v - 1});
            }
        }
        sort(a.begin(),a.end());
        int ans = 0;
        for(auto& [x,y] : a){
            if(budget < x){
                break;
            }
            int c = min(y,budget / x);
            budget -= c * x;
            ans += c * 2;
        }
        return ans + budget / minv;
    }
};