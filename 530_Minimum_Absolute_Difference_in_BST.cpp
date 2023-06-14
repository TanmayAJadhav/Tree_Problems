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
    int prev;
    int ans;
    void helper(TreeNode* root)
    {
        if(!root)
        {
            return;
        }
        helper(root->left);
        if(prev != -1)
        {
            ans = min(ans, (root->val)-prev);
        }
        prev = root->val;
        helper(root->right);
    }
    
    int getMinimumDifference(TreeNode* root) 
    {
        ans = INT_MAX;
        prev = -1;
        helper(root);
        return ans;   
    }
};