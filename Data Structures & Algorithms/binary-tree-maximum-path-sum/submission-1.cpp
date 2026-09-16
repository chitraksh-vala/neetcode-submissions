class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;

        auto solve = [&](auto&& self, TreeNode* root) -> int {
            if (root == nullptr)
                return 0;

            int leftsum = max(0, self(self, root->left));
            int rightsum = max(0, self(self, root->right));

            int landroot = leftsum + root->val;
            int randroot = rightsum + root->val;
            int landrandroot = leftsum + rightsum + root->val;

            ans = max(ans, max(landroot, max(randroot, landrandroot)));

            return max(landroot, randroot);
        };

        solve(solve, root);
        return ans;
    }
};