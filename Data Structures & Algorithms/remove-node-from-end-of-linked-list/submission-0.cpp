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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        int length = 0;
        ListNode* curr=head;
        while(curr)
        {
            length++;
            curr=curr->next;
        }   
        int index=-1;
        ListNode* prev=nullptr;
        curr=head;
        while(index<length-n-1)
        {
            prev=curr;
            curr=curr->next;
            index++;
        }
        if(curr==head)
        {
            head=head->next;
        }
        else
        {
        prev->next=curr->next;
        }
        return head;
    }
};
