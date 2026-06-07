class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        const int MAX_VAL = 100001;
        TreeNode* nodeMap[MAX_VAL] = {nullptr};
        bool hasParent[MAX_VAL] = {false};

        for (const auto& desc : descriptions) {
            int pVal = desc[0];
            int cVal = desc[1];
            int isLeft = desc[2];

            if (!nodeMap[pVal]) {
                nodeMap[pVal] = new TreeNode(pVal);
            }
            if (!nodeMap[cVal]) {
                nodeMap[cVal] = new TreeNode(cVal);
            }

            if (isLeft) {
                nodeMap[pVal]->left = nodeMap[cVal];
            } else {
                nodeMap[pVal]->right = nodeMap[cVal];
            }

            hasParent[cVal] = true;
        }

        for (const auto& desc : descriptions) {
            int pVal = desc[0];
            if (!hasParent[pVal]) {
                return nodeMap[pVal];
            }
        }

        return nullptr;
    }
};