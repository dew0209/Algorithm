class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i = 0;i < n;i++){
            map<int,int> cnt;
            map<int,int> count;
            for(int j = i;j < n;j++){
                if(cnt.contains(nums[j])){
                    count[cnt[nums[j]]]--;
                    if(count[cnt[nums[j]]] == 0){
                        count.erase(cnt[nums[j]]);
                    }
                    cnt[nums[j]]++;
                    count[cnt[nums[j]]]++;
                }else {
                    cnt[nums[j]]++;
                    count[1]++;
                }
                int l = j - i + 1;
                if((count.size() == 1 && cnt.size() == 1) || (count.size() == 2 && count.rbegin()->first == count.begin()->first * 2)){
                    res = max(res,l);
                }
            }
            
        }
        return res;
    }
};