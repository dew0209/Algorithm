//https://leetcode.cn/problems/rank-transform-of-an-array/?envType=daily-question&envId=2026-07-12

class Solution {
public:
    map<int,int> tol;
    int idx = 1;
    int get_re(int u){
        if(!tol.contains(u)){
            tol[u] = idx++;
        }
        return tol[u];
    }
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> cnt(n,0);
        iota(cnt.begin(),cnt.end(),1);
        sort(cnt.begin(),cnt.end(),[&](int a,int b){
            return arr[a - 1] < arr[b - 1];
        });
        for(int i = 0;i < n;i++){
            int id = cnt[i] - 1;
            arr[id] = get_re(arr[id]);
        }
        return arr;
    }
};