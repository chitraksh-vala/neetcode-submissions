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
    vector<int> sorted(TreeNode* root)
    {   
        vector<int> node;
        if(root==nullptr)
        {
            return node;
        }
        node.push_back(root->val);
        vector<int> leftnode=sorted(root->left);
        vector<int> rightnode=sorted(root->right);
        leftnode.insert(leftnode.end(), node.begin(), node.end());
        leftnode.insert(leftnode.end(), rightnode.begin(), rightnode.end());
        return leftnode;
    }

    int kthSmallest(TreeNode* root, int k) 
    {
        vector<int> sort=sorted(root);
        return sort[k-1];
    }
};
