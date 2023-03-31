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

    unordered_map<int,int>inordermap;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        for(int i = 0; i < inorder.size(); i++)
        {
            inordermap[inorder[i]] = i;
        }    
        int n = inorder.size();
        TreeNode* root = buildtree(0, n-1, 0, n-1, preorder, inorder);
        return root;
    }

    TreeNode* buildtree(int instart, int inend, int prestart, int preend, vector<int>& preorder,vector<int>& inorder)
    {
        if(prestart > preend || instart> inend)
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(preorder[prestart]);
        int inRoot = inordermap[root->val];
        int numsLeft = inRoot - instart;

        root->left = buildtree(instart, inRoot-1, prestart+1, prestart+numsLeft,preorder,inorder);
        root->right = buildtree(inRoot+1, inend, prestart+numsLeft+1, preend,preorder,inorder);

        return root;
    }


};