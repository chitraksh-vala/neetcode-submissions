class Solution {
public:

    int goodNodes(TreeNode* root)
    {
        return dfs(root, root->val);
    }

    int dfs(TreeNode* root, int maxVal)
    {
        if (root == nullptr)
            return 0;

        int good = 0;

        if (root->val >= maxVal)
        {
            good++;
        }

        maxVal = max(maxVal, root->val);

        good += dfs(root->left, maxVal);
        good += dfs(root->right, maxVal);

        return good;
    }
};