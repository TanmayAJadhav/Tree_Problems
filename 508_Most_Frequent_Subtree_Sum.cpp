class Solution {
public:
    int maxsum;
    unordered_map<int,int>mp;

    int postorder(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }

        int left = postorder(root->left);
        int right = postorder(root->right);
        int sum = root->val + left + right;

        mp[sum]++;
        maxsum = max(maxsum,mp[sum]);
        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root)
    {
        maxsum = 0;
        vector<int>ans;
        postorder(root); 
        
        cout<<maxsum<<endl;
        for(auto it:mp)
        {
        cout<<it.first<<" : "<<it.second<<endl;
            if(it.second==maxsum)
            {
                ans.push_back(it.first);
            }
        }   
        return ans;
    }
};