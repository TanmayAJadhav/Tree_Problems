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
    bool helper(TreeNode* root1, TreeNode* root2)
    {
        if(root1 == NULL && root2 == NULL)
        {
            return true;
        }

        if(root1 == NULL)
        {
            if(root2!=NULL)
            {
                return false;
            }
        }

        if(root2 == NULL)
        {
            if(root1!=NULL)
            {
                return false;
            }
        }
        
        if(root1->val != root2->val)
        {
            return false;
        }

        bool leftequ = helper(root1->left,root2->left);
        bool leftnotequ = helper(root1->left,root2->right);
        bool rightequ = helper(root1->right,root2->right);
        bool rightnotequ = helper(root1->right,root2->left);
         
        return (leftequ || leftnotequ) && (rightequ || rightnotequ);

    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) 
    {
        return helper(root1, root2);    
    }
};