class Solution {
public:
    int sumRootToLeaf(TreeNode* root, int currentSum = 0) {
        if (!root) return 0;

        // Update the current sum: shift left and add current bit
        // currentSum << 1 is the same as currentSum * 2
        currentSum = (currentSum << 1) | root->val;

        // If it's a leaf node, return the path's total
        if (!root->left && !root->right) {
            return currentSum;
        }

        // Otherwise, continue down the tree
        return sumRootToLeaf(root->left, currentSum) + 
               sumRootToLeaf(root->right, currentSum);
    }
};