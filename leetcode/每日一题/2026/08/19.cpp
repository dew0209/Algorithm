//https://leetcode.cn/problems/cinema-seat-allocation/description/?envType=daily-question&envId=2026-08-19

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int,int> cnt;
        int left = 0b00001111;
        int middle = 0b11000011;
        int right = 0b11110000;
        for(auto& reserved : reservedSeats){
            if(reserved[1] >= 2 && reserved[1] <= 9){
                cnt[reserved[0]] |= (1 << (reserved[1] - 2));
            }
        }
        int res = (n - cnt.size()) * 2;
        for(auto [row,mask] : cnt){
            if((left | mask) == left || (middle | mask) == middle || (right | mask) == right){
                res++;
            }
        }
        return res;
    }
};