//https://leetcode.cn/problems/find-a-safe-walk-through-a-grid/description/?envType=daily-question&envId=2026-07-02

const int N = 2500,INF = 0x3f3f3f3f;
class Solution {
public:

    int n,m;
    int g[N][N];
    int d[N];
    int st[N];
    int t = 0;

    int dijkstr(){
        memset(d,0x3f,sizeof d);
        d[0] = t;
        for(int i = 0;i < n;i++){
            int t = -1;
            for(int j = 0;j < n;j++){
                if((t == -1 || d[t] > d[j]) && !st[j]){
                    t = j;
                }
            }
            st[t] = 1;
            for(int i = 0;i < n;i++){
                d[i] = min(d[i],d[t] + g[t][i]);
            }
        }
        if(d[n - 1] == INF)return -1;
        return d[n - 1];
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n1 = grid.size();
        int m1 = grid[0].size();
        memset(g,0x3f,sizeof g);
        t = grid[0][0];
        for(int i = 0;i < n1;i++){
            for(int j = 0;j < m1;j++){
                int x = grid[i][j];
                if(i - 1 >= 0){
                    g[(i - 1) * m1 + j][i * m1 + j] = x;
                }
                if(i + 1 < n1){
                    g[(i + 1) * m1 + j][i * m1 + j] = x;
                }
                if(j + 1 < m1){
                    g[i * m1 + j + 1][i * m1 + j] = x;
                }
                if(j - 1 >= 0){
                    g[i * m1 + j - 1][i * m1 + j] = x;
                }
            }
        }
        
        n = n1 * m1;
        
        int res = dijkstr();
        cout << res << endl;
        return res != -1 && res < health;
    }
};