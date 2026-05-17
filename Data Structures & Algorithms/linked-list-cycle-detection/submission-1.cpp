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
    bool hasCycle(ListNode* head) {
        if(not head) return false;
        ListNode* fast = head->next;
        while(fast and fast->next and fast->next->next) {
            if(head == fast) return true;
            head = head->next;
            fast = fast->next->next;
        }
        return false;
    }
};
