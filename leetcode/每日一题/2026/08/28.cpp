//https://leetcode.cn/problems/lexicographically-smallest-palindromic-permutation-greater-than-target/?envType=daily-question&envId=2026-08-28

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int left[26]{};
        for (char b : s) {
            left[b - 'a']++;
        }
        auto valid = [&]() -> bool {
            for (int c : left) {
                if (c < 0) {
                    return false;
                }
            }
            return true;
        };

        string mid_ch;
        for (int i = 0; i < 26; i++) {
            int c = left[i];
            if (c % 2 == 0) {
                continue;
            }
            // s 不能有超过一个字母出现奇数次
            if (!mid_ch.empty()) {
                return "";
            }
            // 记录填在正中间的字母
            mid_ch = 'a' + i;
            left[i]--;
        }

        int n = s.size();
        // 先假设答案左半与 t 的左半（不含正中间）相同
        for (int i = 0; i < n / 2; i++) {
            left[target[i] - 'a'] -= 2;
        }

        if (valid()) {
            // 特殊情况：把 target 左半翻转到右半，能否比 target 大？
            string right_s = target.substr(0, n / 2);
            ranges::reverse(right_s);
            right_s = mid_ch + right_s;
            if (right_s > target.substr(n / 2)) { // 由于左半是一样的，所以只需比右半
                return target.substr(0, n / 2) + right_s;
            }
        }

        for (int i = n / 2 - 1; i >= 0; i--) {
            int b = target[i] - 'a';
            left[b] += 2; // 撤销消耗
            if (!valid()) { // [0,i-1] 无法做到全部一样
                continue;
            }

            // 把 target[i] 增大到 j
            for (int j = b + 1; j < 26; j++) {
                if (left[j] == 0) {
                    continue;
                }

                // 找到答案（下面的循环在整个算法中只会跑一次）
                left[j] -= 2;
                target.resize(i + 1);
                target[i] = 'a' + j;
    
                // 中间的空位可以随便填
                for (int k = 0; k < 26; k++) {
                    target += string(left[k] / 2, 'a' + k);
                }
    
                // 镜像翻转
                string right_s = target;
                ranges::reverse(right_s);
                target += mid_ch;
                target += right_s;
    
                return target;
            }
            // 增大失败，继续枚举
        }
        return "";
    }
};