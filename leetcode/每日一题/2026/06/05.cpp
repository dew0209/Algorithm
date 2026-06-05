//https://leetcode.cn/problems/total-waviness-of-numbers-in-range-ii/?envType=daily-question&envId=2026-06-05

typedef long long ll;

class Solution {
public:

    struct State{
        //前两位，前一位，前缀是否一样，是否前导0
        int prev,curr,tight,lead;

        //合法数字的个数，波动值的数量
        ll cnt,sum;
    };

    ll sove(ll num){
        if(num < 100)return 0;
        string s = to_string(num);
        int n = s.size();

        vector<State> currStates;
        //10表示无效状态，也就是前一位和前两位数字都没，1 ，1 ，1，0分别表示前缀是否一样，是否前导0，合法数字的个数（一开始为空值，设置为1），波动之的数量为0
        currStates.push_back({10,10,1,1,1,0});

        for(int pos = 0;pos < n;++pos){
            int limit = s[pos] - '0';
            ll cnt[2][2][11][11] = {0};
            ll sum[2][2][11][11] = {0};
            for(const auto& st : currStates){
                int maxv= st.tight ? limit : 9;
                for(int digit = 0;digit <= maxv;digit++){
                    int newLead = st.lead && (digit == 0);
                    int newPrev = st.curr;
                    int newCurr = newLead ? 10 : digit;
                    int newTight = st.tight && (digit == maxv);
                    ll add = 0;
                    if(!newLead && st.prev != 10 && st.curr != 10){
                        if ((st.prev < st.curr && st.curr > digit) || 
                            (st.prev > st.curr && st.curr < digit)) {
                            add = st.cnt;
                        }
                    }
                    cnt[newTight][newLead][newPrev][newCurr] += st.cnt;
                    sum[newTight][newLead][newPrev][newCurr] += st.sum + add;
                }
            }
            //收集合法状态
            vector<State> nextStates;
            for(int tight = 0;tight < 2;tight++){
                for(int lead = 0;lead < 2;lead++){
                    for(int prev = 0;prev <= 10;prev++){
                        for(int curr = 0;curr <= 10;curr++){
                            ll c = cnt[tight][lead][prev][curr];
                            ll s = sum[tight][lead][prev][curr];
                            if(c != 0){
                                nextStates.push_back({prev, curr, tight, lead, c, s});
                            }
                        }
                    }
                }
            }
            currStates.swap(nextStates);
        }

        ll ans = 0;
        for(const auto& st : currStates){
            ans += st.sum;
        }
        return ans;
    }

    long long totalWaviness(long long num1, long long num2) {
        return sove(num2) - sove(num1 - 1);
    }
};