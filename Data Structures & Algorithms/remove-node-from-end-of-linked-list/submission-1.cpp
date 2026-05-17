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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(not head) return head;
        ListNode* advance = head;
        int counter = 1;
        while(counter < n) {
            advance = advance->next;
            ++counter;
        }
        ListNode* copy = head;
        ListNode* prev = nullptr;
        while(advance and advance->next) {
            prev = copy;
            copy = copy->next;
            advance = advance->next;

        }
        // ListNode* dlt = copy;
        if(prev) prev->next = copy->next;
        else return copy->next;
        return head;
    }
};
