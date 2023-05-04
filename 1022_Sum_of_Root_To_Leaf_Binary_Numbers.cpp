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

    int helper(TreeNode* root, int ans)
    {
        if(root==NULL)
        {
            return 0; 
        }
        ans = 2*ans + root->val;

        if(root->left == NULL && root->right==NULL)
        {
            return ans;
        }

        int leftpart = helper(root->left,ans);
        int rightpart = helper(root->right,ans);

        return leftpart + rightpart;
    }

    int sumRootToLeaf(TreeNode* root) 
    {
        return helper(root,0);    
    }
};1022. Sum of Root To Leaf Binary Numbers