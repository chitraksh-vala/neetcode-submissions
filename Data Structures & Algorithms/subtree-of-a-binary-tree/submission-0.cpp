/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
bool isSameTree(TreeNode* p, TreeNode* q)
{
    // Both are empty
    if(p == nullptr && q == nullptr)
        return true;

    // One is empty, other isn't
    if(p == nullptr || q == nullptr)
        return false;

    // Values don't match
    if(p->val != q->val)
        return false;

    // Check both subtrees
    return isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}


bool isSubtree(TreeNode* root, TreeNode* subRoot)
{
    // Empty subRoot is always a subtree
    if(subRoot == nullptr)
        return true;

    // root became empty, but subRoot isn't
    if(root == nullptr)
        return false;

    // Either:
    // 1. subRoot starts at root
    // 2. subRoot is in left subtree
    // 3. subRoot is in right subtree
    return isSameTree(root, subRoot) ||
           isSubtree(root->left, subRoot) ||
           isSubtree(root->right, subRoot);
}
};
