/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int>ans;
        map<int,int>mp;
        queue<pair<Node*, int>>q;
        
        q.push({root,0});
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int vertical = it.second;
            
            if(mp.find(vertical) == mp.end())
            {
                mp[vertical] = node->data;
            }
            
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
