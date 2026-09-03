//https://leetcode.cn/problems/construct-uniform-parity-array-i/?envType=daily-question&envId=2026-09-02


//直接return true就行
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int a = 0;
        int b = 0;
        for(auto nums : nums1){
            if(nums % 2 == 1){
                a++;
            }else {
                b++;
            }
        }
        bool aflag = true;
        bool bflag = true;

        for(auto nums : nums1){
            if(nums % 2 != 1){
                //当前数是偶数，想构造奇数
                if(!a){
                    aflag = false;
                    break;
                }

            }
        }
        for(auto nums : nums1){
            if(nums % 2 != 0){
                //当前数是奇数，想构造偶数
                if(a - 1 < 0){
                    bflag = false;
                    break;
                }

            }
        }
        return aflag || bflag;
    }
};