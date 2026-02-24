class Solution {
public:
    int sumRootToLeaf(TreeNode* root, int currentSum = 0) {
        if (!root) return 0;

        currentSum = (currentSum << 1) | root->val;

        if (!root->left && !root->right) {
            return currentSum;
        }

        return sumRootToLeaf(root->left, currentSum) + 
               sumRootToLeaf(root->right, currentSum);
    }
};