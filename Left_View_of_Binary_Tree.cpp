

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   vector<int>ans;
        queue<Node*>q;
        if(!root)
        {
            return ans;
        }
        q.push(root);
        while(!q.empty())
        {
            int sze = q.size();
            int last = 0;
            for(int i = 0; i < sze; ++i)
            {
                Node* node = q.front();
                q.pop();
                if(i==0)
                {
                    last = (node->data);
                    ans.push_back(last);
                }
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
        }
        return ans;
}