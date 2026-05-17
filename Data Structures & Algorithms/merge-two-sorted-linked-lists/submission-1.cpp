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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* merged_head = new ListNode(0);
        ListNode* head_copy = merged_head;
        while(list1 and list2) {
            if(list1->val < list2->val) {
                head_copy -> next = list1;
                list1 = list1->next;
            }
            else {
                head_copy -> next = list2;
                list2 = list2->next;
            }
            head_copy = head_copy->next;
        }
        if(list1) {
            head_copy->next = list1;
        }
        if(list2) {
            head_copy->next = list2;
        }
        return merged_head->next;
    }
};
