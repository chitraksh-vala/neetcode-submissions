class Solution {
public:
    queue<TreeNode*> q1;
    queue<TreeNode*> q2;
    vector<int> res;
    vector<int> level;

    vector<int> rightSideView(TreeNode* root)
    {
        if (root == nullptr)
            return res;

        q2.push(root);

        while (!(q1.empty() && q2.empty()))
        {
            if (q1.empty())
            {
                q1 = q2;
                q2 = queue<TreeNode*>();

                // Last node of current level = rightmost node
                res.push_back(q1.back()->val);
            }

            TreeNode* node = q1.front();
            q1.pop();

            if (node != nullptr)
            {
                if (node->left != nullptr)
                    q2.push(node->left);

                if (node->right != nullptr)
                    q2.push(node->right);
            }
        }

        return res;
    }
};