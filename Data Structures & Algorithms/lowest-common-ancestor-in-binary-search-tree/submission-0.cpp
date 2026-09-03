class Solution {
public:

    unordered_set<TreeNode*> elements(TreeNode* root)
    {
        unordered_set<TreeNode*> res;

        if(root == nullptr)
        {
            return res;
        }

        res.insert(root);

        unordered_set<TreeNode*> left = elements(root->left);
        unordered_set<TreeNode*> right = elements(root->right);

        res.insert(left.begin(), left.end());
        res.insert(right.begin(), right.end());

        return res;
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == nullptr)
        {
            return nullptr;
        }

        if(root == p || root == q)
        {
            return root;
        }

        unordered_set<TreeNode*> left = elements(root->left);
        unordered_set<TreeNode*> right = elements(root->right);

        if(left.count(p) && left.count(q))
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if(right.count(p) && right.count(q))
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        else
        {
            return root;
        }
    }
};