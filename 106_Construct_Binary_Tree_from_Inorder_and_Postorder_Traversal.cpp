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
    unordered_map<int,int>inMap;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        int n = inorder.size();
        if(n != postorder.size())
        {
            return NULL;

        }
        for(int i = 0; i < n; i++)
        {
            inMap[inorder[i]] = i;
        }    

        return buildTree(0, n-1, 0, n-1, inorder, postorder);
    }

    TreeNode* buildTree(int inStart, int inEnd, int pStart, int pEnd, vector<int>& inorder, vector<int>& postorder)
    {
        if(inStart > inEnd || pStart > pEnd)
        {
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[pEnd]);
        int inRoot = inMap[postorder[pEnd]];
        int numLeft = inRoot - inStart;

        root->left = buildTree(inStart, inRoot-1, pStart, pStart + numLeft-1,inorder,postorder);
        root->right = buildTree(inRoot+1, inEnd, pStart + numLeft, pEnd-1, inorder, postorder);

        return root;
    }
};