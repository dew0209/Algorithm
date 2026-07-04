//https://leetcode.cn/problems/minimum-score-of-a-path-between-two-cities/?envType=daily-question&envId=2026-07-04

#define x first
#define y second

using namespace std;
typedef pair<int,int> PII;
const int N = 1500010,INF = 0x3f3f3f3f;

class Solution {
public:

    int n,m;
    int h[N],e[N],ne[N],w[N],idx;
    int d[N];
    bool st[N];

    void add(int a,int b,int c){
        e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx++;
    }

    int dijkstr(){
        memset(d,0x3f,sizeof d);
        //d[1] = 0;
        priority_queue<PII,vector<PII>,greater<PII>> q;
        q.push({d[1],1});
        while(q.size()){
            auto t = q.top();
            q.pop();
            
            int u = t.y,distance = t.x;
            //cout << u << " --- " << distance << endl;
            
            for(int i = h[u];~i;i = ne[i]){
                int j = e[i];
                int mv = min(distance,w[i]);
                //cout << mv << " --- " << w[i] << endl;
                if(d[j] > mv){
                    d[j] = mv;
                    q.push({d[j],j});
                }
            }
        }
        if(d[n] == INF)return -1;
        return d[n];
    }



    int minScore(int nnode, vector<vector<int>>& roads) {
        n = nnode;
        m = roads.size();
        memset(h,-1,sizeof h);
        for(int i = 0;i < m;i++){
            int a,b,c;
            a = roads[i][0];
            b = roads[i][1];
            c = roads[i][2];
            add(a,b,c);
            add(b,a,c);
        }
        int t = dijkstr();
        return t;
    }
};