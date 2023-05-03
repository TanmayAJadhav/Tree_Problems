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
    string str;
    int ans;
    void helper(TreeNode* root)
    {
        if(root)
        {
            str.push_back(root->val+'0');

            helper(root->left);
            helper(root->right);
            if(root->left == NULL && root->right==NULL)
            {
                ans += stoi(str);
            }
            str.pop_back();
        }
    }

    int sumNumbers(TreeNode* root) {
        str = "";
        ans = 0;
        helper(root);
        return ans;
    }
};