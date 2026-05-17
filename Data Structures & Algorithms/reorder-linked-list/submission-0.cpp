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
    void reorderList(ListNode* head) {
        ListNode* temp = head;
        ListNode* slow = head;
        ListNode* fast = head;
        stack<ListNode*> st;
        while(fast and fast->next) {
            st.push(slow);
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = nullptr;
        if(fast) {
            prev = slow;
            slow = slow->next;
            prev->next = nullptr;
        }
        while(not st.empty() and slow) {
            ListNode* top = st.top();
            ListNode* slow_next = slow->next;
            top->next = slow;
            slow->next = prev;
            prev = top;
            st.pop();
            slow = slow_next;
        }
    }
};
