//https://leetcode.cn/problems/minimum-moves-to-clean-the-classroom/?envType=daily-question&envId=2026-09-01

struct Info{
    int x,y,mask,e,steps;
};
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();

        queue<Info> q;
        vector<vector<int>> cnt(n,vector<int>(m,0));
        int sum = 0;
        int ax = 0,ay = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(classroom[i][j] == 'S'){
                    ax = i;
                    ay = j;
                }else if(classroom[i][j] == 'L'){
                    cnt[i][j] = (1 << sum);
                    sum++;
                }
            }
        }
        vector<vector<vector<int>>> dist(n,vector<vector<int>>(m,vector<int>(1 << sum,-1)));
        dist[ax][ay][0] = energy;
        q.push({ax,ay,0,energy,0});
        while(q.size()){
            auto t = q.front();
            q.pop();
            int bx = t.x;
            int by = t.y;
            int bmask = t.mask;
            int be = t.e;
            int bsteps = t.steps;

            if(bmask == (1 << sum) - 1){
                return bsteps;
            }
            //0可以进来，但是不能做转换了。
            if(be == 0)continue;

            for(int i = 0;i < 4;i++){
                int cx = dx[i] + bx;
                int cy = dy[i] + by;
                if(cx < 0 || cx >= n || cy < 0 || cy >= m)continue;
                if(classroom[cx][cy] == 'X')continue;
                int ne_mask = bmask | cnt[cx][cy];
                int ne_e = classroom[cx][cy] == 'R' ? energy : be - 1;
                if(ne_e > dist[cx][cy][ne_mask]){
                    dist[cx][cy][ne_mask] = ne_e;
                    q.push({cx,cy,ne_mask,ne_e,bsteps + 1});
                }
            }

        }
        return -1;
    }
};