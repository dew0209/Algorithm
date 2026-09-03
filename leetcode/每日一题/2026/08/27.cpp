//https://leetcode.cn/problems/lexicographically-smallest-permutation-greater-than-target/?envType=daily-question&envId=2026-08-27

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int left[26]{};
        for (int i = 0; i < s.size(); i++) {
            left[s[i] - 'a']++;
            left[target[i] - 'a']--; // 消耗 s 中的一个字母 target[i]
        }

        // 从右往左尝试
        for (int i = s.size() - 1; i >= 0; i--) {
            int b = target[i] - 'a';
            left[b]++; // 撤销消耗

            bool ok = true;
            for (int c : left) {
                if (c < 0) { // [0,i-1] 无法做到全部一样
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                continue;
            }

            // 把 target[i] 增大到 j
            for (int j = b + 1; j < 26; j++) {
                if (left[j] == 0) {
                    continue;
                }

                left[j]--;
                target[i] = 'a' + j;
                target.resize(i + 1);

                for (int k = 0; k < 26; k++) {
                    target += string(left[k], 'a' + k);
                }
                return target;
            }
            // 增大失败，继续枚举
        }
        return "";
    }
};