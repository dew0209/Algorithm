//https://leetcode.cn/problems/rectangle-overlap/description/?envType=daily-question&envId=2026-09-14

class Solution {
public:
    //反向思维
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0],y1 = rec1[1],x2 = rec1[2],y2 = rec1[3];
        int x11 = rec2[0],y11 = rec2[1],x21 = rec2[2],y21 = rec2[3];
        if(x2 <= x11 || y2 <= y11 || y1 >= y21 || x1 >= x21 || x1 == x2 || y1 == y2 || x11 == x21 || y11 == y21){
            return false;
        }
        return true;
    }
};