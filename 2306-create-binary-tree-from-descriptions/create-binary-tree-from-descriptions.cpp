class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // Fast I/O operations
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // Max node value is 100,000 based on constraints
        const int MAX_VAL = 100001;
        
        // Direct-address table for tree node pointers
        // Using a flat array eliminates hash-map overhead
        TreeNode* nodeMap[MAX_VAL] = {nullptr};
        
        // Array to track if a node value has a parent
        bool hasParent[MAX_VAL] = {false};

        for (const auto& desc : descriptions) {
            int pVal = desc[0];
            int cVal = desc[1];
            int isLeft = desc[2];

            // Allocate parent if it doesn't exist yet
            if (!nodeMap[pVal]) {
                nodeMap[pVal] = new TreeNode(pVal);
            }
            // Allocate child if it doesn't exist yet
            if (!nodeMap[cVal]) {
                nodeMap[cVal] = new TreeNode(cVal);
            }

            // Link them directly
            if (isLeft) {
                nodeMap[pVal]->left = nodeMap[cVal];
            } else {
                nodeMap[pVal]->right = nodeMap[cVal];
            }

            // Mark this child as having a parent
            hasParent[cVal] = true;
        }

        // Find the root: look up the parent values present in descriptions
        for (const auto& desc : descriptions) {
            int pVal = desc[0];
            if (!hasParent[pVal]) {
                return nodeMap[pVal];
            }
        }

        return nullptr;
    }
};