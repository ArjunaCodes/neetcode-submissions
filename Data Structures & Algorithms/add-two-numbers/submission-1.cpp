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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry {0};
        ListNode* copy = l1;
        ListNode* prev = nullptr;
        while(l1 and l2) {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum   = sum % 10;
            l1 -> val = sum;
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            int sum  = l1->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            l1->val = sum;
            prev = l1;
            l1 = l1->next;
        }
        l1 = prev;
        while(l2) {
            int sum = l2->val + carry;
            carry  = sum / 10;
            sum  = sum % 10;
            cout<< sum << endl;
            l2->val = sum;
            l1->next = l2;
            l1 = l1->next;
            prev = l1;
            l2 = l2->next;
        }
        if(carry) {
            prev->next = new ListNode(carry);
        }
        return copy;

    }

};
