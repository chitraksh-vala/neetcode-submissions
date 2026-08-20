class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;

        unordered_map<Node*, Node*> corr;

        // Create the copy of the head
        Node* copy = new Node(head->val);
        corr[head] = copy;

        // First pass: create all copied nodes and connect next pointers
        Node* temp1 = head->next;
        Node* temp2 = copy;

        while (temp1) {
            temp2->next = new Node(temp1->val);

            corr[temp1] = temp2->next;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        // Second pass: connect random pointers
        temp1 = head;
        temp2 = copy;

        while (temp1) {
            if (temp1->random)
                temp2->random = corr[temp1->random];
            else
                temp2->random = nullptr;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return copy;
    }
};