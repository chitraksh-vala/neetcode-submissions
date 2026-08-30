class Solution {
public:

    int diameter = 0;

    int height(TreeNode* root)
    {
        if(root == nullptr)
            return 0;

        int left = height(root->left);
        int right = height(root->right);

        // Longest path passing through this node
        diameter = max(diameter, left + right);

        // Height of this node
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root)
    {
        height(root);
        return diameter;
    }
};