//https://leetcode.cn/problems/count-subarrays-with-majority-element-ii/description/?envType=daily-question&envId=2026-06-26


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
        //这里离散化要+1，因为树状数组从1开始，0的话，lowbit(0)一直是0，就死循环了
        return lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
    }

    //lowbit:等于 u 的二进制中最低位的 1 所代表的数值
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

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int m = nums.size();
        vector<int> sums(m + 1,0);
        //sums[0]的值：前缀和从0开始
        a.push_back(0);
        for(int i = 1;i <= m;i++){
            sums[i] = (nums[i - 1] == target ? 1 : -1) + sums[i - 1];
            a.push_back(sums[i]);
            //保证小于sums[i]的数存在
            a.push_back(sums[i] - 1);
        }
        //排序去重
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        //树状数组长度
        n = a.size();
        //将sum[0]入队
        add(find(0),1);

        long long res = 0;
        for(int i = 1;i <= m;i++){
            //统计从sums[0~i - 1]满足小于sums[i]的个数
            int x = sums[i];
            int cnt = sum(find(x - 1));
            //累计结果
            res = res + cnt;
            //将当前点加入到树状数组
            add(find(x),1);
        }
        return res;
    }
};