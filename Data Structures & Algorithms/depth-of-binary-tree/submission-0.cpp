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
    int maxDepth(TreeNode* root) 
    {   
        if(root==nullptr)
        {
            return 0;
        }
        int depth=1;
        queue<TreeNode*> same1;
        queue<TreeNode*> same2;
        same1.push(root);
        while(!same1.empty()||!same2.empty())
        {
            if(same1.empty())
            {
                swap(same1, same2);
                depth++;
            }
            TreeNode* node=same1.front();
            same1.pop();
            if(node->left)
            {
            same2.push(node->left);
            }
            if(node->right)
            {
            same2.push(node->right);
            }
        }
        return depth;
    }
};
