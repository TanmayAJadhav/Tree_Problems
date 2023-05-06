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
    vector<TreeNode*>ans;
    TreeNode* helper(TreeNode* root, unordered_set<int>&s)
    {
        if(root==NULL)
        {
            return NULL;
        }

        root->left = helper(root->left,s);
        root->right = helper(root->right,s);

        if(s.find(root->val) != s.end())
        {
            if(root->left)
            {
                ans.push_back(root->left);
            }

            if(root->right)
            {
                ans.push_back(root->right);
            }

            return NULL;
        }
        return root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
    {
        unordered_set<int>s;

        for(auto x:to_delete)
        {
            s.insert(x);
        }     

        helper(root,s);
        if(s.find(root->val) == s.end())
        {
            ans.push_back(root);
        }
        return ans;
    }
};