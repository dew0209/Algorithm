//https://leetcode.cn/problems/number-of-unique-xor-triplets-i/description/?envType=daily-question&envId=2026-07-23

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        size_t n = nums.size();
        return n <= 2 ? n : 1 << bit_width(n);
    }
};