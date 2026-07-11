//https://leetcode.cn/problems/count-the-number-of-complete-components/?envType=daily-question&envId=2026-07-11


const int N = 100;
class Solution {
public:
    int p[N];
    int cnt[N];
    int size[N];
    int find(int u){
        if(p[u] != u){
            p[u] = find(p[u]);
        }
        return p[u];
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        for(int i = 1;i <= n;i++){
            p[i] = i;
            size[i] = 1;
        }
        for(auto& edge : edges){
            int a = edge[0] + 1;
            int b = edge[1] + 1;
            int pa = find(a);
            int pb = find(b);
            //cout << pa << " --  " << pb << endl;
            if(pa != pb){
                p[pa] = pb;
                size[pb] += size[pa];
                cnt[pb] += cnt[pa] + 1;
            }else {
                cnt[pb]++;
            }
        }
        int res = 0;
        for(int i = 1;i <= n;i++){
            if(p[i] == i && cnt[i] * 2 == size[i] * (size[i] - 1)){
                //cout << i << " --- " << cnt[i] << " --- " << size[i] << endl;
                res++;
            }
        }
        return res;
    }
};