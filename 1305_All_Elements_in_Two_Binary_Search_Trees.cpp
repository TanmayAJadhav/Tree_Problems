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
    vector<int>l1;
    vector<int>l2;

    void inorder(vector<int>&vec, TreeNode* root)
    {
        if(root)
        {
            inorder(vec,root->left);
            vec.push_back(root->val);
            inorder(vec,root->right);
        }
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        inorder(l1,root1);
        inorder(l2,root2);

        int i = 0, j = 0, n = l1.size(), m = l2.size();
        vector<int>ans;
        while(i < n && j < m)
        {
            if(l1[i] < l2[j])
            {
                ans.push_back(l1[i]);
                i++;
            }
            else
            {
                ans.push_back(l2[j]);
                j++;
            }
        }

        while(i < n)
        {
            ans.push_back(l1[i]);
            i++;
        }

        while(j < m)
        {
            ans.push_back(l2[j]);
            j++;
        }

        return ans;
    }
};