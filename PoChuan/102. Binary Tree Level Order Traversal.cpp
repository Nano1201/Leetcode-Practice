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

    // Use a queue
    // Push root node to the queue
    // store the temp size of the queue size, this is the # of the node in the layer
    // print the node in the queue and push into the queue
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> ret;

        if(root == nullptr)
            return ret;

        while(!q.empty()) {

            int level = q.size();
            vector<int> layer;

            for(int i = 0 ; i < level ; i++) {

                auto front = q.front();
                q.pop();
                layer.push_back(front->val);
                if(front->left != nullptr)
                    q.push(front->left);
                if(front->right != nullptr)
                    q.push(front->right);
            }
            ret.push_back(layer);
        }

        return ret;
    }
};