struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        queue<Node*>q;
        q.push(root);
        vector<int>ans;
        
        while(!q.empty())
        {
            int sze = q.size();
            int num;
            for(int i = 0; i < sze; i++)
            {
                Node* node = q.front();
                q.pop();
                
                num = node->data;
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            ans.push_back(num);
        }
        return ans;
    }
};
