class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;

        ListNode* sumlist = new ListNode(0);
        ListNode* curr = sumlist;

        ListNode* curr1 = l1;
        ListNode* curr2 = l2;

        while (curr1 || curr2 || carry) {
            int sum = carry;

            if (curr1) {
                sum += curr1->val;
                curr1 = curr1->next;
            }

            if (curr2) {
                sum += curr2->val;
                curr2 = curr2->next;
            }

            int digit = sum % 10;
            carry = sum / 10;

            curr->next = new ListNode(digit);
            curr = curr->next;
        }

        return sumlist->next;
    }
};