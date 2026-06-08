//https://leetcode.cn/problems/partition-array-according-to-given-pivot/description/?envType=daily-question&envId=2026-06-08

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> a;
        vector<int> b;
        vector<int> c;
        int n = nums.size();
        for(int i = 0;i < n;i++){
            int x = nums[i];
            if(x < pivot){
                a.push_back(i);
            }else if(x > pivot){
                b.push_back(i);
            }else {
                c.push_back(i);
            }
        }
        vector<int> res;
        for(auto t : a){
            res.push_back(nums[t]);
        }
        for(auto t : c){
            res.push_back(nums[t]);
        }
        for(auto t : b){
            res.push_back(nums[t]);
        }
        return res;
    }
};