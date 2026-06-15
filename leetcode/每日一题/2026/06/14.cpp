//https://leetcode.cn/problems/maximum-twin-sum-of-a-linked-list/?envType=daily-question&envId=2026-06-14

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> cnt;
        while(head != nullptr){
            cnt.push_back(head->val);
            head = head->next;
        }
        int res = 0;
        int n = cnt.size();
        for(int i = 0;i < n / 2;i++){
            res = max(res,cnt[i] + cnt[n - 1 - i]);
        }
        return res;
    }
};