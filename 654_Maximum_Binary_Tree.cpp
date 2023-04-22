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

    int findMax(vector<int>& nums, int start, int end)
    {
        int maxele = 0, maxInd = 0;
        for(int i = start; i <= end; i++)
        {
            if(maxele < nums[i])
            {
                maxele = nums[i];
                maxInd = i;
            }
        }
        return maxInd;
    }

    TreeNode* createTree(vector<int>& nums, int start, int end)
    {
        if(start > end)
        {
            return NULL;
        }

        if(start == end)
        {
            return new TreeNode(nums[start]);
        }

        int ind = findMax(nums,start,end);

        TreeNode* root = new TreeNode(nums[ind]);

        root->left = createTree(nums, start, ind-1);
        root->right = createTree(nums, ind+1, end);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        return createTree(nums, 0, nums.size()-1);    
    }
};