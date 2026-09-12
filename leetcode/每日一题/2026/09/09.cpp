//https://leetcode.cn/problems/count-commas-in-range-ii/?envType=daily-question&envId=2026-09-09

class Solution {
public:
    int get_len(long long u){
        int res = 0;
        while(u){
            u /= 10;
            res++;
        }
        return res;
    }
    long long get_v(int len,long long u){
        long long x = 1;
        while(len--)x *= 10;
        return min(x - 1,u);
    }
    long long get_x(int len){
        long long x = 1;
        len--;
        while(len--)x *= 10;
        //cout << " get_x " << x << endl;
        return x;
    }
    long long countCommas(long long n) {
        vector<long long> cnt(20,0);
        int len = get_len(n);
        for(int i = 4;i <= len;i++){
            long long min_v = get_v(i,n);
            cnt[i] = min_v - get_x(i) + 1;
            //cout << min_v << " --- " << get_x(i) << " --- " <<cnt[i] << endl;
        }
        long long res = 0;
        for(int i = 4;i <= len;i++){
            //cout << cnt[i] << " --- " << endl;
            res = res + (cnt[i]) * ((i - 1) / 3);
        }
        return res;
    }
};