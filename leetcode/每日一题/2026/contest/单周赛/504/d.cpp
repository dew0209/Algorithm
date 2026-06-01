class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        map<int,int> pos;
        for(int i = 0;i < n;i++)pos[nums[i]] = i;
        int j=0;
        for(int i = 0;i < n;i = j + 1){
            int mex = 0;
            set<int> cnt;
            for(j = i;j < n;j++){
                cnt.insert(nums[j]);
                while(cnt.count(mex))mex++;
                auto it = pos.find(mex);
                if(it == pos.end() || it->second <= i)break;
            }
            res.push_back(mex);
        }
        return res;
    }
};