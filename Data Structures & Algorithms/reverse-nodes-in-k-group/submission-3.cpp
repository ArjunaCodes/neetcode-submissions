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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(not head) return nullptr;
        int counter = 0;
        ListNode* copy = head;
        while(copy and counter < k) {
            copy = copy->next;
            ++counter;
        }
        if(not copy and counter < k) return head;
        copy = head;
        ListNode* prev = nullptr;
        counter = 0;
        while(counter < k) {
            ListNode* next = copy->next;
            copy->next = prev;
            prev = copy;
            copy = next;
            ++counter;
        }
        head->next = reverseKGroup(copy, k);
        return prev;
    }
};
