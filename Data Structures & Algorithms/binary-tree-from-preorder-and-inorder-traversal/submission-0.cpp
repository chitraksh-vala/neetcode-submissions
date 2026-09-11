class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        int i = 0;
        while (inorder[i] != preorder[0]) {
            i++;
        }

        // Partition preorder and inorder into left and right subtrees
        vector<int> left_pre(preorder.begin() + 1, preorder.begin() + 1 + i);
        vector<int> right_pre(preorder.begin() + 1 + i, preorder.end());

        vector<int> left_in(inorder.begin(), inorder.begin() + i);
        vector<int> right_in(inorder.begin() + i + 1, inorder.end());

        root->left = buildTree(left_pre, left_in);
        root->right = buildTree(right_pre, right_in);

        return root;
    }
};