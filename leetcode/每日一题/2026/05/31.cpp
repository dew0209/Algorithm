//https://leetcode.cn/problems/destroying-asteroids/?envType=daily-question&envId=2026-05-31

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        sort(asteroids.begin(),asteroids.end());
        long long mass1 = mass;
        for(int i = 0;i < n;i++){
            if(mass1 < asteroids[i]){
                return false;
            }
            mass1 += asteroids[i];
        }
        return true;
    }
};