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
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        TreeNode* temp = root;
        TreeNode *newn = new TreeNode(val);
        if(root==NULL)
        {
            root = newn;
            return root;
        }
        while(temp != NULL)
        {
            if(temp->val < val)
            {
                if(temp->right == NULL)
                {
                    temp->right = newn;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
            else
            {
                if(temp->left == NULL)
                {
                    temp->left = newn;
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
        }
        return root;
    }
};