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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if (list1 == nullptr)
            return list2;

        if (list2 == nullptr)
            return list1;

        ListNode* head;

        if (list1->val < list2->val)
        {
            head = list1;
        }
        else
        {
            head = list2;
        }

        ListNode* curr1;
        ListNode* curr2;

        if (head == list1)
        {
            curr1 = list1->next;
            curr2 = list2;
        }
        else
        {
            curr1 = list1;
            curr2 = list2->next;
        }

        ListNode* curr = head;

        while (curr1 || curr2)
        {
            if (curr1 && (!curr2 || curr1->val < curr2->val))
            {
                curr->next = curr1;
                curr = curr->next;
                curr1 = curr1->next;
            }
            else
            {
                curr->next = curr2;
                curr = curr->next;
                curr2 = curr2->next;
            }
        }

        return head;
    }
   ListNode* mergeKLists(vector<ListNode*>& lists)
{
    if (lists.empty())
        return nullptr;

    int n = lists.size();

    while (n > 1)
    {
        int j = 0;

        for (int i = 0; i < n; i += 2)
        {
            if (i + 1 < n)
                lists[j++] = mergeTwoLists(lists[i], lists[i + 1]);
            else
                lists[j++] = lists[i];
        }

        n = j;
    }

    return lists[0];
}
};
