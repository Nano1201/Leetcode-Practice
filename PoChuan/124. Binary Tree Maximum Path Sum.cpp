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

 // Use dfs to find the optimal path
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        
        int maxNum = INT_MIN;

        auto dfs = [&](TreeNode* node, auto &&dfs) -> int{

            if(node == NULL)
                return 0;
            // Single node
            int singleNum = node->val;
            
            int leftNum = INT_MIN;
            int rightNum = INT_MIN;
            int bothNum = INT_MIN;
            // Left node
            leftNum = max(0, dfs(node->left, dfs));

            // Right node
            rightNum = max(0, dfs(node->right, dfs));
            
            // both left and right
            bothNum = rightNum + leftNum + singleNum;

            maxNum = max(maxNum, bothNum);

            return singleNum + max(leftNum, rightNum);
        };

        dfs(root, dfs);
        
        return maxNum;
    }
};