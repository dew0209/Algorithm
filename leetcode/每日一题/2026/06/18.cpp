//https://leetcode.cn/problems/angle-between-hands-of-a-clock/description/?envType=daily-question&envId=2026-06-18

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double d = abs(hour * 30 - minutes * 5.5);
        return min(d,360 - d);
    }
};