//https://leetcode.cn/problems/number-of-ways-to-assign-edge-weights-ii/description/?envType=daily-question&envId=2026-06-12


const int N = 100010,M = N * 2,MOD = 1e9 + 7;

class Solution {
public:
    int n,m;
    int h[N],e[M],ne[M],idx;
    int f[N][18];
    int d[N];
    int q[N];
    int depth[N];
    int mulN[N];

    void add(int a,int b){
        e[idx] = b,ne[idx] = h[a],h[a] = idx++;
    }

    void bfs(int root,int fa){
        memset(depth,0x3f,sizeof depth);
        int hh = 0,tt = 0;
        q[0] = root;
        depth[0] = 0,depth[root] = 1;
        while(hh <= tt){
            int u = q[hh++];
            for(int j = h[u];~j;j = ne[j]){
                int k = e[j];
                if(k == fa)continue;
                if(depth[k] > depth[u] + 1){
                    f[k][0] = u;
                    depth[k] = depth[u] + 1;
                    d[k] = d[u] + 1;
                    q[++tt] = k;
                    for(int c = 1;c <= 17;c++){
                        f[k][c] = f[f[k][c - 1]][c - 1];
                    }
                }
            }
        }
    }

    int lca(int a,int b){
        if(depth[a] < depth[b])swap(a,b);
        for(int k = 17;k >= 0;k--){
            if(depth[f[a][k]] >= depth[b]){
                a = f[a][k];
            }
        }

        if(a == b)return a;

        for(int k = 17;k >= 0;k--){
            if(f[a][k] != f[b][k]){
                a = f[a][k];
                b = f[b][k];
            }
        }
        return f[a][0];
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        mulN[0] = 1;
        for(int i = 1;i < N;i++){
            mulN[i] = mulN[i - 1] * 2LL % MOD;
        }

        n = edges.size() + 1;
        m = edges.size();
        memset(h,-1,sizeof h);
        int root = 1;
        for(auto& it : edges){
            int a = it[0];
            int b = it[1];
            add(a,b);
            add(b,a);
        }
        bfs(root,-1);
        vector<int> res;
        for(auto& q : queries){
            int a = q[0];
            int b = q[1];
            int distance = d[a] * 1LL + d[b] - 2 * d[lca(a,b)];
            //cout << distance << " ==== " << lca(a,b) << " === " << d[a] << " === " << d[b] << endl;
            if(distance == 0){
                res.push_back(0);
            }else {
                //cout << distance << endl;
                res.push_back(mulN[distance - 1]);
            }
            
        }
        return res;
    }
};