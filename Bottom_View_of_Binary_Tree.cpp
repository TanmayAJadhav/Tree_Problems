//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int>ans;
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        
        q.push({root,0});
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            Node* node = it.first;
            int vertical = it.second;
            
            mp[vertical] = node->data;    
            
            if(node->left)
            {
                q.push({node->left,vertical-1});
            }
            if(node->right)
            {
                q.push({node->right,vertical+1});
            }
        }
        
        
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};