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
    bool level(TreeNode* root,int maxval,int minval)
    {
        bool current=false;
        bool total;
        if(root==nullptr)
        {
            return true;
        }
        if(root->val>minval && root->val<maxval)
        {
            current=true;
        }
        total=(current&&level(root->left,min(maxval,root->val),minval)&&level(root->right,maxval,max(minval,root->val)));
        return total;
    }
    bool isValidBST(TreeNode* root) 
    {
        return level(root,1000000000,-1000000000);
    }
};
