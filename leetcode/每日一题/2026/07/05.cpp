//https://leetcode.cn/problems/number-of-paths-with-max-score/?envType=daily-question&envId=2026-07-05


int dx[3] = {-1,-1,0};
int dy[3] = {0,-1,-1};
const int MOD = 1e9 + 7;
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<long long>> f(n + 1,vector<long long>(n + 1,0));
        vector<vector<long long>> cnt(n + 1,vector<long long>(n + 1,0));
        cnt[1][1] = 1;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                char c = board[i - 1][j - 1];
                if(c == 'X')continue;
                int source = 0;
                if(c != 'E' && c != 'S'){
                    source = c - '0';
                }
                for(int t = 0;t < 3;t++){
                    int ai = i + dx[t];
                    int aj = j + dy[t];
                    if(ai < 1 || aj < 1)continue;
                    if(board[ai - 1][aj - 1] == 'X')continue;
                    if(cnt[ai][aj] == 0)continue;
                    long long ne_source = (source + f[ai][aj]) % MOD;
                    if(ne_source > f[i][j]){
                        f[i][j] = ne_source;
                        cnt[i][j] = cnt[ai][aj];
                    }else if(ne_source == f[i][j]){
                        cnt[i][j] = (cnt[i][j] + cnt[ai][aj]) % MOD;
                    }
                }
            }

        }
        vector<int> res(2,0);
        res[0] = f[n][n];
        res[1] = cnt[n][n];
        return res;
    }
};