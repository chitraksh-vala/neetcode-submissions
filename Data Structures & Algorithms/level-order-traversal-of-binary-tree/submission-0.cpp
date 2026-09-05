class Solution {
public:
    queue<TreeNode*> q1;
    vector<int> level;
    vector<vector<int>> res;
    queue<TreeNode*> q2;

    vector<vector<int>> levelOrder(TreeNode* root)
    {
        if (root == nullptr)
            return res;

        q2.push(root);
        level.push_back(root->val);

        while (!(q1.empty() && q2.empty()))
        {
            if (q1.empty())
            {
                q1 = q2;
                q2 = queue<TreeNode*>();

                res.push_back(level);
                level = vector<int>();
            }

            TreeNode* node = q1.front();
            q1.pop();

            if (node != nullptr)
            {
                if (node->left != nullptr)
                {
                    q2.push(node->left);
                    level.push_back(node->left->val);
                }

                if (node->right != nullptr)
                {
                    q2.push(node->right);
                    level.push_back(node->right->val);
                }
            }
        }

        // Add the last level
        if (!level.empty())
            res.push_back(level);

        return res;
    }
};