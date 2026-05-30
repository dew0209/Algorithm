//https://leetcode.cn/problems/block-placement-queries/description/?envType=daily-question&envId=2026-05-30


const int N = 50010;
class Solution {
public:

    int tr[N];

    int lowbit(int u){
        return u & -u;
    }

    int query(int u){
        int res = 0;
        for(int i = u;i;i -= lowbit(i)){
            res = max(res,tr[i]);
        }
        return res;
    }

    void upate(int u,int c){
        for(int i = u;i < N;i += lowbit(i)){
            tr[i] = max(tr[i],c);
        }
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        //树状数组
        int mx = N - 1;
        set<int> st = {0,mx};
        for(auto& q : queries){
            if(q[0] == 1){
                st.insert(q[1]);
            }
        }
        int pre = 0;
        for(int x : st){
            if(x == 0){
                continue;
            }
            upate(x,x - pre);
            pre = x;
        }
        reverse(queries.begin(),queries.end());
        vector<bool> ans;
        for(auto& q : queries){
            
            if(q[0] == 2){
                int x = q[1];
                int sz = q[2];
                auto it = st.upper_bound(x);
                --it;
                int pre = *it;
                int max_len = query(pre);
                max_len = max(max_len,x - pre);
                ans.push_back(max_len >= sz);
            }else {
                int x = q[1];
                auto it = st.find(x);
                int pre = *prev(it);
                int nxt = *next(it);
                upate(nxt,nxt - pre);
                st.erase(it);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};