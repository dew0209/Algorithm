//https://leetcode.cn/problems/delete-the-middle-node-of-a-linked-list/description/?envType=daily-question&envId=2026-06-15

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
    ListNode* deleteMiddle(ListNode* head) {
        int count = 0;
        ListNode* headTmp = head;
        while(head != nullptr){
            count++;
            head = head->next;
        }
        if(count == 1){
            return nullptr;
        }
        int mid = count / 2;
        ListNode* prev = nullptr;
        ListNode* res = headTmp;
        while(mid--){
            prev = headTmp;
            headTmp = headTmp->next;
        }
        prev->next = headTmp->next;
        return res;
    }
};