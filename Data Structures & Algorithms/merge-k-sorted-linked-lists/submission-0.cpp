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
    ListNode* merge_two_llist(ListNode* left, ListNode* right) {
        ListNode* merger = new ListNode(0);
        ListNode* copy = merger;
        while(left and right) {
            if(left->val < right->val) {
                merger->next = left;
                merger = merger->next;
                left = left->next;
            }
            else {
                merger->next = right;
                merger = merger->next;
                right = right->next;
            }
        }
        if(left) {
            merger->next = left;
        }
        if(right) {
            merger->next = right;
        }
        ListNode* head = copy->next;
        delete copy;
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if(size == 0) return nullptr;
        if(size == 1) return lists[0];
        ListNode* merged = merge_two_llist(lists[0], lists[1]);
        for(int i=2; i<size; ++i) {
            merged = merge_two_llist(merged, lists[i]);
        }
        return merged;
    }
};
