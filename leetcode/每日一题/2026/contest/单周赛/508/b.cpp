typedef pair<int,int> PII;
#define fi first
#define se second
#define pb push_back
const int N = 100010;

class Solution {
public:
    int n;
    vector<PII> q;
    vector<PII> res;
    
    void get_res(){
        int st = -2e9,ed = -2e9;
        for(int i = 0;i < n;i++){
            auto t = q[i];
            if(t.fi - 1 > ed){
                if(st != -2e9){
                    res.pb({st,ed});
                }
                st = t.fi;
            }
            ed = max(ed,t.se);
        }
        if(st != -2e9){
            res.pb({st,ed});
        }
    }

    vector<int> get_ans(int a,int b){
        vector<int> ans(2,0);
        ans[0] = a;
        ans[1] = b;
        return ans;
    }
    
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& arr, int l, int r) {
        for(auto& arrItem : arr){
            q.push_back({arrItem[0],arrItem[1]});
        }
        n = q.size();
        sort(q.begin(),q.end());
        get_res();

        vector<vector<int>> ans;
        for(auto& re : res){
            int x = re.first;
            int y = re.second;
            //cout << x << " --- " << y << endl;
            if(x < l && y > l){
                ans.push_back(get_ans(x,l - 1));
                if(y > r){
                    ans.push_back(get_ans(r + 1,y));
                }
            }else if(x < r && y > r){
                ans.push_back(get_ans(r + 1,y));
            }else if(x >= l && y <= r){
                
            }else if(y == l){
                ans.push_back(get_ans(x,y - 1));
            }else if(x == r){
                ans.push_back(get_ans(x + 1,y));
            }else {
                ans.push_back(get_ans(x,y));
            }
        }
        return ans;
    }
};