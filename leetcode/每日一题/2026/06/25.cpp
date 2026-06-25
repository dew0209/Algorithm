//https://leetcode.cn/problems/count-subarrays-with-majority-element-i/description/?envType=daily-question&envId=2026-06-25


const int N = 200010;


class Solution {
public:
    //树状数组的长度:从1到n
    int n;
    //树状数组
    int tr[N];
    //离散化数组
    vector<int> a;

    //离散化函数
    int find(int x){
        return lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
    }

    //lowbit
    int lowbit(int u){
        return u & -u;
    }

    //树状数组求和
    int sum(int u){
        int res = 0;
        for(int i = u;i;i -= lowbit(i)){
            res += tr[i];
        }
        return res;
    }

    ////树状数组单点修改
    void add(int a,int b){
        for(int i = a;i <= n;i += lowbit(i))tr[i] += b;
    }

    int countMajoritySubarrays(vector<int>& nums, int target) {
        int m = nums.size();
        vector<int> sums(m + 1,0);
        a.push_back(0);
        for(int i = 1;i <= m;i++){
            sums[i] = (nums[i - 1] == target ? 1 : -1) + sums[i - 1];
            a.push_back(sums[i]);
            a.push_back(sums[i] - 1);
        }
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        n = a.size();
        //将sum[0]入队
        add(find(0),1);

        long long res = 0;
        for(int i = 1;i <= m;i++){
            int x = sums[i];
            int cnt = sum(find(x - 1));
            res = res + cnt;
            add(find(x),1);
        }
        return res;
    }
};