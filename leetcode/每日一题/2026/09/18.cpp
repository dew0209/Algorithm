//https://leetcode.cn/problems/maximum-number-of-non-overlapping-substrings/description/?envType=daily-question&envId=2026-09-18

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        map<char,pair<int,int>> pos;
        for(int i = 0;i < n;i++){
            char d = s[i];
            if(pos.find(d) == pos.end()){
                pos[d] = {i,i};
            }else {
                pos[d].second = i;
            }
        }

        //合法的
        vector<pair<int,int>> val;

        for(auto [ch,p] : pos){
            
            int l = p.first,r = p.second;

            int nl = l;
            int nr = l;

            //还要继续扩展
            while(nl >= l || nr <= r){
                int i = (nl >= l) ? nl : nr;

                int pos_l = pos[s[i]].first;
                int pos_r = pos[s[i]].second;

                if(pos_l < l){
                    l = pos_l;
                }

                if(pos_r > r){
                    r = pos_r;
                }

                if(i == nl){
                    nl--;
                }

                if(i == nr){
                    nr++;
                }

            }

            val.push_back({l,r});

        }

        sort(val.begin(),val.end(),[](const pair<int,int>& a,const pair<int,int>& b){
            return a.second < b.second;
        });

        vector<string> ans;

        int end = -1;

        for(auto& [left,right] : val){
            
            if(left > end){
                ans.push_back(s.substr(left,right - left + 1));
                end = right;
            }
        }
        return ans;
    }
};