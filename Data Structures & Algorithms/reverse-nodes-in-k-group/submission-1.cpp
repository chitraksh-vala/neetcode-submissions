class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* curr = head;
        vector<ListNode*> heads;
        vector<ListNode*> backs;
        int kk = 0;

        while(curr)
        {  
            if(kk == 0)
            {
                if(!(curr->next))
                {
                    heads.push_back(curr);   // FIX 1: record trailing singleton instead of dropping it
                    curr = curr->next;
                }
                else
                {
                    heads.push_back(curr);
                    curr = curr->next;
                    kk = k - 1;
                }
            }
            else if(kk == 1)
            {
                backs.push_back(curr);
                curr = curr->next;
                kk--;
            }
            else
            {
                curr = curr->next;
                kk--;
            }
        }

        for(int i = 0; i < backs.size(); i++)
        {  
            kk = k;

            ListNode* currhead = heads[i];
            curr = currhead;
            ListNode* prev;

            if(i + 1 < backs.size())
            {
                prev = backs[i + 1];
            }
            else if(i + 1 < heads.size())
            {
                prev = heads[i + 1];
            }
            else
            {
                prev = nullptr;
            }

            while(curr && kk)
            {
                if(curr->next)
                {
                    ListNode* temp = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = temp;
                    kk--;
                }
                else
                {
                    curr->next = prev;
                    break;
                }
            }
        }

        if(backs.empty())        // FIX 2: check backs, not heads, before indexing backs[0]
            return head;

        return backs[0];
    }
};